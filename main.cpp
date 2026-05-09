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
// before keeping the rest of the string as the last element.
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
            else if(tok == "/") {
                std::string val = std::to_string(left / right);
                st.push(val);
            }
            else if(tok == "%") {
                std::string val = std::to_string(left % right);
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
            else if(tok == "!=") {
                if(left != right) {
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

    // Program counter - determines what line we are on.
    int pc = 0;
    
    // The number of failed ifs encountered to skip 
    // to correct endif on failed condition.
    int count_if = 0;

    // The number of endifs encountered.
    int count_endif = 0;

    while(pc < lines.size()) {
        std::string line = lines[pc];

        auto commentIndex = line.find("//");

        if(commentIndex != std::string::npos) {
            line = line.substr(0, commentIndex);
        }

        std::vector<std::string> lineVec = split(line, 1);

        if(lineVec[0] == "") {
            pc++;
        }
        else if(lineVec[0] == "if") {
            if(eval_expr(lineVec[1]) == "1") {
                pc++;
            }
            else {
                pc++;
                count_if++;

                // Tracks if an else branch exists on if statement fail
                bool branch_else = false;

                // Advance line by line counting the number of nested 
                // ifs and endifs. Skip to the correct endif.
                while(count_endif < count_if) {
                    std::string keyword = split(lines[pc], 1)[0];

                    while(keyword != "endif") {
                        if(keyword == "if") {
                            count_if++;
                        }
                        else if(keyword == "else") {
                            branch_else = true;
                            break;
                        }

                        pc++;
                        keyword = split(lines[pc], 1)[0];
                    }

                    pc++;

                    // Skip to else branch
                    if(branch_else) {
                        break;
                    }

                    count_endif++;
                }
            }
        }
        else if(lineVec[0] == "else") {
            // Note: this is reached when an if-else 
            // statement's if branch is successful
            while(split(lines[pc], 1)[0] != "endif") {
                pc++;
            }

            pc++;
        }
        else if(lineVec[0] == "endif") {
            pc++;
            count_endif++;
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
        else if(lineVec[0] == "for") {
            lineVec = split(lineVec[1], 2);
            std::string name = lineVec[0];
            std::string expr = lineVec[2];

            vars[name] = eval_expr(expr);
            pc++;
        }
        else if(lineVec[0] == "until") {
            // Loop if condition is false
            if(eval_expr(split(lines[pc], 1)[1]) == "0") {
                pc++;
            }
            else {
                while(split(lines[pc], 1)[0] != "endfor") {
                    pc++;
                }

                pc++;
            }
        }
        else if(lineVec[0] == "endfor") {
            while(split(lines[pc], 1)[0] != "for") {
                pc--;
            }

            lineVec = split(split(lines[pc], 1)[1], 2);
            std::string name = lineVec[0];

            vars[name] = std::to_string(std::stoi(vars[name]) + 1);
            pc++;
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