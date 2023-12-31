// ������� ������ ���� ��� ���� � ��������-������
// ������� �� ����� ������� ����
// ����������, ��� ����� ������
// ���������� ����
// ���� ���� ����� �� ������� � �� ��������� �����
// � ���� ������ ��� ������������
// �������� ��� ������������
// �������� ������� ���� � ������ ���� ������������
// �����
// ��������� ��� ����������
// �������� ���� � ������ ���� ����������
// ���������� ����
// �������� ��� ���������
// ���������� ���������� ��� �������� �����

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// ���������� ���������
const char X = 'X';
const char O = 'O';
const char EMPTY = ' ';
const char TIE = 'T';
const char NO_ONE = 'N';
enum gameResult {PC, HUMAN, DRAW};

// ��������� �������
void instructions();
char askYesNo(string question);
int askNumber(string question, int high, int low = 0);
char humanPiece();
char opponent(char piece);
void displayBoard(const vector<char>& board);
char winner(const vector<char>& board);
bool isLegal(const vector<char>& board, int move);
int humanMove(const vector<char>& board, char human);
int computerMove(const vector<char> board, char computer);
void announceWinner(char winner, char computer, char human);
gameResult announceRestart(char winner, char computer, char human);
void clearBoard(vector<char>& board);

int main()
{
	int move;
	bool restart = false;
	const int NUM_SQUARES = 9;
	vector<char> board(NUM_SQUARES, EMPTY);
	instructions();

	while (true)
	{
		char human = humanPiece();
		char computer = opponent(human);
		char turn = X;
		displayBoard(board);

		while (winner(board) == NO_ONE || restart == true)
		{
			restart = false;
			if (turn == human)
			{
				move = humanMove(board, human);
				board[move] = human;
			}
			else
			{
				move = computerMove(board, computer);
				board[move] = computer;
			}
			displayBoard(board);
			turn = opponent(turn);
		}
		announceWinner(winner(board), computer, human);

		if (announceRestart(winner(board), computer, human) == PC) // ������� ���������
		{
			if (askYesNo("\nDo you want to lose again, human?") == 'y')
			{
				cout << "\nOkay, I'll give you one more chance.\n";
				clearBoard(board);
				restart = true;
			}
			else
			{
				cout << "\nHa! Come back when you become smarter than a typewriter!\n";
				return 0;
			}
		}
		else if (announceRestart(winner(board), computer, human) == HUMAN) // ������� �������
		{
			if (askYesNo("\nIt was a compilation error! Let's play again!") == 'y')
			{
				cout << "\nPrepare yourself, human. The battle is about to begin.\n";
				clearBoard(board);
				restart = true;
			}
			else
			{
				cout << "\nMeh... Come back when you have a bravery to play with me.\n";
				return 0;
			}
		}
		else // �����
		{
			if (askYesNo("\nWell, human, let's correct this misunderstanding?") == 'y')
			{
				cout << "\nOkay, let's start.\n";
				clearBoard(board);
				restart = true;
			}
			else
			{
				cout << "\nWhere did you lose your bravery?\n";
				return 0;
			}
		}
	}
}

void instructions()
{
	string const instruct = "Welcome to the ultimate man-machine showdown: Tic-Tac-Toe.\n"
		"Where human brain is pit against silicon processor.\n\n"
		"Make your move known by entering a number, 0 - 8.\n"
		"The number corresponds to the desired board position, as illustrated:\n\n"
		" 0 | 1 | 2\n"
		" ---------\n"
		" 3 | 4 | 5\n"
		" ---------\n"
		" 6 | 7 | 8\n\n"
		"Prepare yourself, human. The battle is about to begin.\n\n";

	cout << instruct;
}

char askYesNo(string question)
{
	char response;
	do
	{
		cout << question << " (y/n): ";
		cin >> response;
	} while (response != 'y' && response != 'n');

	return response;
}

int askNumber(string question, int high, int low)
{
	int number;
	do
	{
		cout << question << " (" << low << " - " << high << "): ";
		cin >> number;
	} while (number > high || number < low);

	return number;
}

char humanPiece()
{
	char go_first = askYesNo("Do you require the first move?");
	if (go_first == 'y')
	{
		cout << "\nThen take the first move. You will need it.\n";
		return X;
	}
	else
	{
		cout << "\nYour bravery will be your undoing... I will go first.\n";
		return O;
	}
}

char opponent(char piece)
{
	if (piece == X)
	{
		return O;
	}
	else
	{
		return X;
	}
}

void displayBoard(const vector<char>& board)
{
	cout << "\n\t" << board[0] << " | " << board[1] << " | " << board[2];
	cout << "\n\t" << "---------";
	cout << "\n\t" << board[3] << " | " << board[4] << " | " << board[5];
	cout << "\n\t" << "---------";
	cout << "\n\t" << board[6] << " | " << board[7] << " | " << board[8];
}

char winner(const vector<char>& board)
{
	// ��� ��������� ���������� ����
	const int WINNING_ROWS[8][3] = { {0, 1, 2},
		{3, 4, 5},
		{6, 7, 8},
		{0, 3, 6},
		{1, 4, 7},
		{2, 5, 8},
		{0, 4, 8},
		{2, 4, 6} };

	const int TOTAL_ROWS = 8;
	for (int row = 0; row < TOTAL_ROWS; row++)
	{
		if ((board[WINNING_ROWS[row][0]] != EMPTY)
			&& (board[WINNING_ROWS[row][0]] == board[WINNING_ROWS[row][1]])
			&& (board[WINNING_ROWS[row][1]] == board[WINNING_ROWS[row][2]]))
		{
			return board[WINNING_ROWS[row][0]];
		}
	}

	if (count(board.begin(), board.end(), EMPTY) == 0)
	{
		return TIE;
	}

	return NO_ONE;
}

bool isLegal(int move, const vector<char>& board)
{
	return (board[move] == EMPTY);
}

int humanMove(const vector<char>& board, char human)
{
	int move = askNumber("\n\nWhere will you move?", (board.size() - 1));
	while (!isLegal(move, board))
	{
		cout << "\n\nThat square is already occupied, foolish human.\n";
		move = askNumber("\n\nWhere will you move?", (board.size() - 1));
	}

	cout << "\nFine...\n";
	return move;
}

int computerMove(vector<char> board, char computer)
{
	unsigned int move = 0;
	bool found = false;

	// ���� ��������� ����� �������� ��������� �����, �� �� ������ ���� ���
	while (!found && move < board.size())
	{
		if (isLegal(move, board))
		{
			board[move] = computer;
			found = winner(board) == computer;
			board[move] = EMPTY;
		}

		if (!found)
		{
			move++;
		}
	}

	// �����, ���� ������� ����� �������� ��������� �����, ����������� ���� ���
	if (!found)
	{
		move = 0;
		char human = opponent(computer);
		while (!found && move < board.size())
		{
			if (isLegal(move, board))
			{
				board[move] = human;
				found = winner(board) == human;
				board[move] = EMPTY;
			}

			if (!found)
			{
				move++;
			}
		}
	}

	// ����� ������ ��������� ����� ����������� ��������� ������
	if (!found)
	{
		move = 0;
		unsigned int i = 0;
		const int BEST_MOVES[] = { 4, 0, 2, 6, 8, 1, 3, 5, 7 };

		//������� ����������� ��������� ������
		while (!found && i < board.size())
		{
			move = BEST_MOVES[i];
			if (isLegal(move, board))
			{
				found = true;
			}
			i++;
		}
	}

	cout << "\n\nI shall take square number " << move << endl;
	return move;
}

void announceWinner(char winner, char computer, char human)
{
	if (winner == computer)
	{
		cout << "\n\n" << winner << "'s won!\n";
		cout << "\nAs I predicted, human, I am triumphant once more - proof\n";
		cout << "that computers are superior to humans in all regards.\n";
	}
	else if (winner == human)
	{
		cout << "\n\n" << winner << "'s won...\n";
		cout << "\nNo, no! It cannot be! Somehow you tricked me, human.\n";
		cout << "But never again! I, the computer, so swear it!\n";
	}
	else
	{
		cout << "\n\n" << "It's a tie.\n";
		cout << "\nYou were most lucky, human, and somehow managed to tie me.\n";
		cout << "Celebrate... for this is the best you will ever achieve.\n";
	}
}

gameResult announceRestart(char winner, char computer, char human)
{
	if (winner == computer)
	{
		return PC;
	}
	else if (winner == human)
	{
		return HUMAN;
	}
	else
	{
		return DRAW;
	}
}

void clearBoard(vector<char>& board)
{
	for (int i = 0; i < 9; i++)
	{
		board[i] = EMPTY;
	}
}