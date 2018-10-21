#include <bits/stdc++.h>

using namespace std;
const string no_label = "#";
int main()
{
	ifstream source_file("code.txt");

	vector <string> file_lines;

	//read all the lines in the source code file
	string line;
	while(getline(source_file, line))
		file_lines.push_back(line);

    	vector<string> labels_tokens, operations_tokens, operands_tokens;

	//Tokenize each line from the source code

	for(string line : file_lines)
	{
		//cout<<line<<endl;
       		vector<string> tokens;
		string current_token = "";
		bool move_to_next_token = false;

       		for(int i = 0, l = line.length(); i<l; i++)
        	{	
			
			

           		if(isspace(line[i]))
            		{
				if(move_to_next_token)
				{
					tokens.push_back(current_token);
                    			current_token = "";
					move_to_next_token = false;
				}
                    		while(i<l && isspace(line[i+1]))
                    			i++;
			}

           		else
                        {
				current_token += line[i];
				move_to_next_token = true;
			}

        	}

       		if(tokens.size() == 2) // The case where there aren't any labels for the current instruction
       		{
            		string no_label = "#";
            		labels_tokens.push_back(no_label);
            		operations_tokens.push_back(tokens[0]);
            		operands_tokens.push_back(tokens[1]);
        	}
        	else if(tokens.size() == 3)
        	{
            		labels_tokens.push_back(tokens[0]);
            		operations_tokens.push_back(tokens[1]);
            		operands_tokens.push_back(tokens[2]);
        	}

	}


	for(int i=0, l = operations_tokens.size(); i<l;i++)
		cout<<labels_tokens[i]<<" "<<operations_tokens[i]<<" "<<operands_tokens[i]<<endl;

	//Construct a symbol table for all the symbolic labels used by the programmer
	unordered_map<string, string> symbols_table;
	return 0;
}
