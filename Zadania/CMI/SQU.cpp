#include <iostream>
#include <queue>

using namespace std;

constexpr int cube_size = 6;

bool is_letter_in_cube(const vector<vector <char>> matrix, const char letter, const int qube);
bool missing_char_cnt(string word, int cubes_cnt, const vector<vector <char>> matrix, vector<bool> used_cubes);


bool missing_char_cnt(string word, int cubes_cnt, const vector<vector <char>> matrix, vector<bool> used_cubes)
{


	for (int i = 0; i < cubes_cnt; i++)
	{
		if (!(used_cubes[i]) && (is_letter_in_cube(matrix, word[0], i)))
		{
			if (word.length() == 1)
			{
				return true;

			}
			{
				used_cubes[i] = true;
				string temp_word = word;
				temp_word.erase(0, 1);
				if (missing_char_cnt(temp_word, cubes_cnt, matrix, used_cubes)) 
				{
					return true;
				}
				else 
				{
					used_cubes[i] = false;
				}
			}
		}
	}
	return false;
}

bool is_letter_in_cube(const vector<vector <char>> matrix, const char letter, const int qube)
{
	for (int i = 0; i < cube_size; i++)
	{
		if (matrix[qube][i] == letter)
		{
			return true;
		}
	}
	return false;
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	unsigned int  questions_cnt;
	cin >> questions_cnt;
	vector<int> output(questions_cnt, -1);

	for (int quest = 0; quest < questions_cnt; quest++)
	{
		int cubes_cnt;
		cin >> cubes_cnt;
		string word;
		cin >> word;
		vector<char> row(cube_size, '0');
		vector<vector <char>> matrix(cubes_cnt, row);

		for (int column = 0; column < cubes_cnt; column++)
		{
			for (int row = 0; row < 6; row++)
			{
				char input;
				cin >> input;
				for (int i = 0; i < word.length(); i++)
				{
					if (word[i] == input)
					{
						matrix[column][row] = input;
					}
				}
			}
		}
		vector<bool> used_cubes(cubes_cnt, false);
		if (missing_char_cnt(word, cubes_cnt, matrix, used_cubes)) 
		{
			cout << "TAK" << endl;
		}
		else 
		{
			cout << "NIE" << endl;
		}
	}
}
