#include <bits/stdc++.h> 

using namespace std;

int main()
{
	ifstream source_file("code.txt");
	
	vector <string> file_lines;

	//read all the lines in the source code file	
	string line;
	while(getline(source_file, line))
		file_lines.push_back(line);

	//Tokenize each line
	regex instructions_regex("\s*[a-zA-Z]+\s+[a-zA-Z]+\s+[a-fA-F0-9']+");
	vector<string> opcodes, addressing_modes, addresses;
	for(string line : file_lines)
	{
		cout<<"Instruction: "<<line<<" is ";

		//if(regex_match(line, instructions_regex))
		if(true)
		{
			cout<<"correct instruction\n";
			vector<string> tokens(3);
			
			int j = 0;
			bool move_to_next_token = false;
			
			for(int i = 0, l = line.length(); i<l; i++)
			{
				if(line[i] == ' ')
				{	
					if(move_to_next_token)
					{	
						tokens[j].push_back('\0');
						j++;
						move_to_next_token = false;
					}
					while(i<l && line[i+1] == ' ')
						i++;
				}
				else
				{
					tokens[j].push_back(line[i]);
					move_to_next_token = true;
				}
			}

			if(tokens.size() == 2)
			{
				opcodes.push_back("");
				addressing_modes.push_back(tokens[0]);
				addresses.push_back(tokens[1]);
			}
			else if(tokens.size() == 3)
			{
				opcodes.push_back(tokens[0]);
				addressing_modes.push_back(tokens[1]);
				addresses.push_back(tokens[2]);
			}

		}
		else
			cout<<"wrong instruction\n";
	}
		
	for(int i=0, l = addressing_modes.size(); i<l;i++)
		cout<<opcodes[i]<<" "<<addressing_modes[i]<<" "<<addresses[i]<<endl;
	return 0;
}
