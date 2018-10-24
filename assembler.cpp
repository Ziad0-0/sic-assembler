#include <bits/stdc++.h>

using namespace std;

string no_label = "?";


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


/*	for(int i=0, l = operations_tokens.size(); i<l;i++)
		cout<<labels_tokens[i]<<" "<<operations_tokens[i]<<" "<<operands_tokens[i]<<endl;
	*/
	unordered_map<string, pair<string, string>> opcodes_table;

	ifstream optable_file("optable.txt");
	string mnemonic_opcode, num, machine_opcode;
	while(getline(optable_file,line))
	{	
		char *current_line = new char[line.length()+1];
		strcpy(current_line, line.c_str());
		mnemonic_opcode = strtok(current_line," ");
		num = strtok(NULL, " ");
		machine_opcode = strtok(NULL, " ");
		pair<string, string> temp;
		temp.first = num;
		temp.second = machine_opcode;
		opcodes_table[mnemonic_opcode] = temp;			
	}
	
/*	for(auto it : opcodes_table)
		cout<<it.first<<" "<<it.second.first<<" "<<it.second.second<<endl;
*/	
	// Convert mnemonic opcodes to machine language opcodes
	for(int i = 0, s =  operations_tokens.size(); i < s; i++)
	{	
		if(operations_tokens[i].compare("Start") == 0 || operations_tokens[i].compare("End") == 0)
			continue;
		string machine_opcode = opcodes_table[operations_tokens[i]].second;
		operations_tokens[i] = machine_opcode;
	}
/*
	for(int i = 0, s = labels_tokens.size(); i < s; i++)
		cout<<labels_tokens[i]<<" "<<operations_tokens[i]<<" "<<operands_tokens[i]<<endl;
*/
	int start_address = 0, end_address = 0;
	//Check if the code writer defined a start address, if it is said used as a start address, else use 0 as a start address
	if(operations_tokens[0].compare("Start") == 0)
		start_address = stoi(operands_tokens[0],NULL,16);
		
	//Construct a symbol table for all the symbolic labels used by the programmer
	int current_address = start_address;
	unordered_map<string, int> symbols_table;
	for(int i = 0, s = labels_tokens.size(); i < s; i++)
	{
		if(i == 0 && operations_tokens[0].compare("Start") == 0)
			continue;
		
		
		if(operations_tokens[i].compare("BYTE") == 0)
		{	
			int num_of_chars = operands_tokens[i].length() - 3; // we reduced 3 because there is 3 characters that we don't want to count
									    // the C or X and the two single quotes
			current_address += (1* ceil(num_of_chars/2.0));
		}
		else if(operations_tokens[i].compare("WORD") == 0)
			current_address += 3;
		else if(operations_tokens[i].compare("RESW") == 0)
			current_address += (stoi(operands_tokens[i])*3);
		else if(operations_tokens[i].compare("RESB") == 0)
			current_address += stoi(operands_tokens[i]);
		else
			current_address += 3;

		//if the current instruction has a label, put it int the symbols table with its address
		if(labels_tokens[i].compare(no_label) != 0)
			symbols_table[labels_tokens[i]] = current_address;
	}
/*	
	cout<<"Symbols Table:";
	cout<<"--------------\n";
	for(auto it: symbols_table)
		cout<<it.first<<" "<<hex<<it.second<<endl;
*/

	//Change all the constants in the code to their correspondant addresses
	for(int i = 0, s = operands_tokens.size(); i < s; i++)
		//Replace the current operand with its address if its exist in the symbols table
		if(symbols_table.count(operand_tokens[i])

	return 0;
}
