// Aiden K Morris
// C++ translation of a tutorial by Dr. Laurie Tratt
// Link: https://youtu.be/Q2UDHY5as90?si=wbjvZ6I1SvFIPA_c
// See README.md for what the original version included and what I have added
#include <iostream>
#include <string>
#include <fstream>
#include <stack>
#include <vector>
#include <cctype>
#include <sstream>
#include <unordered_map>

// Global
std::unordered_map<std::string, std::string> vars;

// My version of Python's split() function.
// Optional max_split determines number of times to split
//   before keeping the rest of the string as the last element
std::vector<std::string> split(std::string s, const int max_split = -1) {
    std::vector<std::string> tokens;
    
    std::istringstream iss(s);
    std::string tok;

    int i = 0;
    std::string end = "";

    while(iss >> tok) {
        if(max_split == -1) {
            tokens.push_back(tok);
        } 
        else {
            if(i < max_split) {
                tokens.push_back(tok);
            }
            else {
                end += tok + " ";
            }
        }

        i++;
    }

    if(max_split != -1) {
        tokens.push_back(end);
    }

    return tokens;
}

std::string eval_expr(std::string s) {
    std::vector<std::string> tokens = split(s);
    
    std::stack<std::string> st;

    for(auto tok : tokens) {
        if(std::isdigit(tok[0])) {
            st.push(tok);
        } 
        else if(vars.count(tok)) {
            st.push(vars[tok]);
        }
        else {
            int right = std::stoi(st.top());
            st.pop();
            int left = std::stoi(st.top());
            st.pop();

            if(tok == "+") {
                std::string val = std::to_string(left + right);
                st.push(val);
            }
            else if(tok == "-") {
                std::string val = std::to_string(left - right);
                st.push(val);
            }
            else if(tok == "*") {
                std::string val = std::to_string(left * right);
                st.push(val);
            }
            else if(tok == "==") {
                if(left == right) {
                    st.push("1");
                }
                else {
                    st.push("0");
                }
            }
            else if(tok == ">=") {
                if(left >= right) {
                    st.push("1");
                }
                else {
                    st.push("0");
                }
            }
            else if(tok == "<=") {
                if(left <= right) {
                    st.push("1");
                }
                else {
                    st.push("0");
                }
            }
            else if(tok == ">") {
                if(left > right) {
                    st.push("1");
                }
                else {
                    st.push("0");
                }
            }
            else if(tok == "<") {
                if(left < right) {
                    st.push("1");
                }
                else {
                    st.push("0");
                }
            }
        }
    }

    return st.top();
}

int main() {
    std::ifstream read("code.txt");

    std::vector<std::string> lines;

    std::string line;

    while(std::getline(read, line)) {
        lines.push_back(line);
    }

    int pc = 0;

    while(pc < lines.size()) {
        std::string line = lines[pc];
        std::vector<std::string> lineVec = split(line, 1);

        if(lineVec[0] == "") {
            pc++;
        }
        else if(lineVec[0] == "if") {
            if(eval_expr(lineVec[1]) == "1") {
                pc++;
            }
            else {
                while(split(lines[pc], 1)[0] != "endif") {
                    pc++;
                }

                pc++;
            }
        }
        else if(lineVec[0] == "endif") {
            pc++;
        }
        else if(lineVec[0] == "while") {
            if(eval_expr(lineVec[1]) == "1") {
                pc++;
            }
            else {
                while(split(lines[pc], 1)[0] != "endwhile") {
                    pc++;
                }

                pc++;
            }
        }
        else if(lineVec[0] == "endwhile") {
            while(split(lines[pc], 1)[0] != "while") {
                pc--;
            }
        }
        else {
            lineVec = split(line, 2);
            std::string name = lineVec[0];
            std::string expr = lineVec[2];

            vars[name] = eval_expr(expr);
            pc++;
        }
    }

    for(auto v : vars) {
        std::cout << v.first << " " << v.second << std::endl;
    }

    return 0;
}