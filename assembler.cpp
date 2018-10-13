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
	vector<string> first_tokens, second_tokens, third_tokens;
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
				first_tokens.push_back("");
				second_tokens.push_back(tokens[0]);
				third_tokens.push_back(tokens[1]);
			}
			else if(tokens.size() == 3)
			{
				first_tokens.push_back(tokens[0]);
				second_tokens.push_back(tokens[1]);
				third_tokens.push_back(tokens[2]);
			}

		}
		else
			cout<<"wrong instruction\n";
	}
		
	for(int i=0, l = second_tokens.size(); i<l;i++)
		cout<<first_tokens[i]<<" "<<second_tokens[i]<<" "<<third_tokens[i]<<endl;
	return 0;
}
