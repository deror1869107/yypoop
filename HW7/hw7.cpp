#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

class Exec {
public:
    virtual ~Exec()
    {

    }

    string execute(const vector<string> &cmd, string text)
    {
        string_process(cmd, text);
        return text;
    }

private:
    virtual void string_process(const vector<string> &cmd, string &text) = 0;
};

class Cat: public Exec {
    void string_process(const vector<string> &cmd, string &text)
    {
        if(cmd.size() <= 2){
            cout << text;
        }
    }
};

class Removetag: public Exec {
    void string_process(const vector<string> &cmd, string &text)
    {
        //removetag
        string remove_char = "=+,.\'\\\"!-;()";
        for(char &c : remove_char){
            text.erase(remove(text.begin(), text.end(), c), text.end());
        }
    }
};

class Shell {
public:
    Shell(string filename):cmd_cnt(0)
    {
        script.open(filename, fstream::in);
    }

    ~Shell()
    {
        script.close();
    }

    void start()
    {
        string line;
        while(getline(script, line)){
            if(readline(line)) return;
        }
    }

private:
    bool readline(const string &line)
    {
        stringstream ss;
        ss << line;
        string input;
        vector<string> command;
        cout << "% " << ss.str() << endl;
        while(ss >> input){
            command.push_back(input);
        }
        if(!command.empty() && command[0] == "exit") return true;
        execute(command);
        return false;
    }

    void execute(const vector<string> &cmd)
    {
        ++cmd_cnt;
        Exec *exec;
        if(cmd[0] == "cat"){
            exec = new Cat;
        } else if(cmd[0] == "removetag"){
            exec = new Removetag;
        } else {
            cout << "unknow command" << endl;
            --cmd_cnt;
            return;
        }
        string text = input(cmd);
        string output_text = exec->execute(cmd, text);
        output(cmd, output_text);
        delete exec;
    }

    string input(const vector<string> &cmd)
    {
        if(detect_pipe()){
            return read_pipe();
        } else {
            return read_file(cmd[1]);
        }
    }

    bool detect_pipe()
    {
        return pipe.find(cmd_cnt) != pipe.end();
    }

    string read_pipe()
    {
        string text = pipe[cmd_cnt];
        pipe.erase(cmd_cnt);
        return text;
    }

    string read_file(const string &filename)
    {
        string text, line;
        fstream input;
        input.open(filename, fstream::in);
        while(getline(input, line)){
            text += line;
            text.push_back('\n');
        }
        input.close();
        return text;
    }

    void output(const vector<string> &cmd, const string &text)
    {
        if(cmd.size() > 2){
            string op = cmd[cmd.size() - 2];
            if(op == ">"){
                redirection(cmd.back(), text);
            } else if(op == "|"){
                pipeline(cmd.back(), text);
            }
        }
    }

    void redirection(const string& filename, const string &text)
    {
        fstream output;
        output.open(filename, fstream::out);
        output << text;
        output.close();
    }

    void pipeline(const string &line_num, const string &text)
    {
        int num = stoi(line_num);
        pipe[cmd_cnt + num] += text;
    }

    fstream script;
    int cmd_cnt;
    map<int, string> pipe;
};

int main(int argc, char **argv)
{
    Shell shell(argv[1]);
    shell.start();
    return 0;
}
