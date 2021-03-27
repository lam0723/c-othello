// Chan Cheuk Lam 1155129258 1155129258@link.cuhk.edu.hk
#include <iostream>
#include <string>
using namespace std;
const int N = 8; // board size

void printBoard(char board[N][N]) { // print game board
	cout << "   "; // print first line
	for (char c = 'A'; c < 'A' + N; c++) {
		cout << c << " ";
	}
	cout << endl;

	for (int i = 0; i < N; i++) { // print the rest
		if (i < 9) cout << " ";
		cout << i + 1 << " ";
		for (int j = 0; j < N; j++) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}

void initial(char board[N][N]) { // initial game board
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			board[i][j] = '.';
		}
	}
	board[N / 2 - 1][N / 2 - 1] = 'X';
	board[N / 2 - 1][N / 2] = 'O';
	board[N / 2][N / 2 - 1] = 'O';
	board[N / 2][N / 2] = 'X';
}

void addPits(char board[N][N], int pits) { // add pits
	string position;
	bool ok = 1;
	int x, y;

	for (int i = 0; i < pits; i++) {
		do { // get a valid input
			ok = 1;
			cout << "Enter position of pit " << i + 1 << ": ";
			cin >> position;
			x = toupper(position[0]) - 65;
			y = stoi(position.substr(1)) - 1;
			if (x > N - 1 || x < 0) ok = 0;
			else if (y > N - 1 || y < 0) ok = 0;
			else if (board[y][x] != '.') ok = 0;
			if (!(ok)) cout << "Invalid position!" << endl;
		} while (!(ok));

		board[y][x] = '#';
	}
}

string FindleftTop(char board[N][N], int round, string position) {
	int x, y;
	string opposite = "";
	char alp;

	alp = position[0];
	x = toupper(alp) - 65;
	if (x > N - 1 || x < 0) return opposite; // check out of boundaries
	y = stoi(position.substr(1)) - 1;
	if (y > N - 1|| y < 0) return opposite;

	if (board[y][x] != '.') return opposite; // check if occupied already

	if (round % 2 == 0) { // O's round
		while (y >= 0 && x >= 0 && opposite == "") { 
			if (board[y][x] == 'O') {
				opposite += alp;
				opposite += to_string(y + 1);
				break;
			}
			x--;
			y--;
			alp--;
			if (x > 0 && y > 0) {
				if (board[y][x] == '.' || board[y][x] == '#') break;
			}
		}
	}
	else { // X's round
		while (y >= 0 && x >= 0 && opposite == "") {
			if (board[y][x] == 'X') {
				opposite += alp;
				opposite += to_string(y + 1);
				break;
			}
			x--;
			y--;
			alp--;
			if (x > 0 && y > 0) {
				if (board[y][x] == '.' || board[y][x] == '#') break;
			}
		}
	}

	return opposite;
}

string FindTop(char board[N][N], int round, string position) {
	int x, y;
	string opposite = "";
	char alp;

	alp = position[0];
	x = toupper(alp) - 65;
	if (x > N - 1 || x < 0) return opposite; // check out of boundaries
	y = stoi(position.substr(1)) - 1;
	if (y > N - 1 || y < 0) return opposite;

	if (board[y][x] != '.') return opposite; // check if occupied already

	if (round % 2 == 0) { // O's round
		while (y >= 0 && opposite == "") {
			if (board[y][x] == 'O') {
				opposite += alp;
				opposite += to_string(y + 1);
				break;
			}
			y--;
			if (x < N) {
				if (board[y][x] == '.' || board[y][x] == '#') break;
			}
		}
	}
	else { // X's round
		while (y >= 0 && opposite == "") { 
			if (board[y][x] == 'X') {
				opposite += alp;
				opposite += to_string(y + 1);
				break;
			}
			y--;
			if (y > 0) {
				if (board[y][x] == '.' || board[y][x] == '#') break;
			}
		}
	}

	return opposite;
}

string FindrightTop(char board[N][N], int round, string position) {
	int x, y;
	string opposite = "";
	char alp;

	alp = position[0];
	x = toupper(alp) - 65;
	if (x > N - 1 || x < 0) return opposite; // check out of boundaries
	y = stoi(position.substr(1)) - 1;
	if (y > N - 1 || y < 0) return opposite;

	if (board[y][x] != '.') return opposite; // check if occupied already

	if (round % 2 == 0) { // O's round
		while (x <= N - 1 && y >= 0 && opposite == "") { 
			if (board[y][x] == 'O') {
				opposite += alp;
				opposite += to_string(y + 1);
				break;
			}
			x++;
			y--;
			alp++;
			if (x < N && y > 0) {
				if (board[y][x] == '.' || board[y][x] == '#') break;
			}
		}
	}
	else { // X's round
		while (x <= N - 1 && y >= 0 && opposite == "") { 
			if (board[y][x] == 'X') {
				opposite += alp;
				opposite += to_string(y + 1);
				break;
			}
			x++;
			y--;
			alp++;
			if (x < N && y > 0) {
				if (board[y][x] == '.' || board[y][x] == '#') break;
			}
		}
	}

	return opposite;
}

string FindLeft(char board[N][N], int round, string position) {
	int x, y;
	string opposite = "";
	char alp;

	alp = position[0];
	x = toupper(alp) - 65;
	if (x > N - 1 || x < 0)	return opposite;// check out of boundaries
	y = stoi(position.substr(1)) - 1;
	if (y > N - 1 || y < 0) return opposite;

	if (board[y][x] != '.') return opposite; // check if occupied already

	if (round % 2 == 0) { // O's round
		while (x >= 0 && opposite == "") { 
			if (board[y][x] == 'O') {
				opposite += alp;
				opposite += to_string(y + 1);
				break;
			}
			x--;
			alp--;
			if (x > 0) {
				if (board[y][x] == '.' || board[y][x] == '#') break;
			}
		}
	}
	else { // X's round
		while (x >= 0 && opposite == "") { 
			if (board[y][x] == 'X') {
				opposite += alp;
				opposite += to_string(y + 1);
				break;
			}
			x--;
			alp--;
			if (x > 0) {
				if (board[y][x] == '.' || board[y][x] == '#') break;
			}
		}
	}
	return opposite;
}

string FindRight(char board[N][N], int round, string position) {
	int x, y;
	string opposite = "";
	char alp;

	alp = position[0];
	x = toupper(alp) - 65;
	if (x > N - 1 || x < 0) return opposite; // check out of boundaries
	y = stoi(position.substr(1)) - 1;
	if (y > N - 1 || y < 0) return opposite;

	if (board[y][x] != '.') return opposite; // check if occupied already

	if (round % 2 == 0) { // O's round
		while (x <= N - 1 && opposite == "") { 
			if (board[y][x] == 'O') {
				opposite += alp;
				opposite += to_string(y + 1);
				break;
			}
			x++;
			alp++;
			if (x < N) {
				if (board[y][x] == '.' || board[y][x] == '#') break;
			}
		}
	}
	else { // X's round
		while (x <= N - 1 && opposite == "") { 
			if (board[y][x] == 'X') {
				opposite += alp;
				opposite += to_string(y + 1);
				break;
			}
			x++;
			alp++;
			if (x < N) {
				if (board[y][x] == '.' || board[y][x] == '#') break;
			}
		}
	}

	return opposite;
}

string FindleftBottom(char board[N][N], int round, string position) {
	int x, y;
	string opposite = "";
	char alp;

	alp = position[0];
	x = toupper(alp) - 65;
	if (x > N - 1 || x < 0) return opposite; // check out of boundaries
	y = stoi(position.substr(1)) - 1;
	if (y > N - 1 || y < 0) return opposite;

	if (board[y][x] != '.') return opposite; // check if occupied already

	if (round % 2 == 0) { // O's round
		while (x >= 0 && y <= N - 1 && opposite == "") {
			if (board[y][x] == 'O') {
				opposite += alp;
				opposite += to_string(y + 1);
				break;
			}
			x--;
			y++;
			alp--;
			if (x > 0 && y < N) {
				if (board[y][x] == '.' || board[y][x] == '#') break;
			}
		}
	}
	else { // X's round
		while (x >= 0 && y <= N - 1 && opposite == "") { 
			if (board[y][x] == 'X') {
				opposite += alp;
				opposite += to_string(y + 1);
				break;
			}
			x--;
			y++;
			alp--;
			if (x > 0 && y < N) {
				if (board[y][x] == '.' || board[y][x] == '#') break;
			}
		}
	}

	return opposite;
}

string FindBottom(char board[N][N], int round, string position) {
	int x, y;
	string opposite = "";
	char alp;

	alp = position[0];
	x = toupper(alp) - 65;
	if (x > N - 1 || x < 0) return opposite; // check out of boundaries
	y = stoi(position.substr(1)) - 1;
	if (y > N - 1 || y < 0) return opposite;

	if (board[y][x] != '.') return opposite; // check if occupied already

	if (round % 2 == 0) { // O's round
		while (y <= N - 1 && opposite == "") {
			if (board[y][x] == 'O') {
				opposite += alp;
				opposite += to_string(y + 1);
				break;
			}
			y++;
			if (y < N) {
				if (board[y][x] == '.' || board[y][x] == '#') break;
			}
		}
	}
	else { // X's round
		while (y <= N - 1 && opposite == "") { 
			if (board[y][x] == 'X') {
				opposite += alp;
				opposite += to_string(y + 1);
				break;
			}
			y++;
			if (y < N) {
				if (board[y][x] == '.' || board[y][x] == '#') break;
			}
		}
	}

	return opposite;
}

string FindrightBottom(char board[N][N], int round, string position) {
	int x, y;
	string opposite = "";
	char alp;

	alp = position[0];
	x = toupper(alp) - 65;
	if (x > N - 1 || x < 0) return opposite; // check out of boundaries
	y = stoi(position.substr(1)) - 1;
	if (y > N - 1 || y < 0) return opposite;

	if (board[y][x] != '.') return opposite; // check if occupied already

	if (round % 2 == 0) { // O's round
		while (x <= N - 1 && y <= N - 1 && opposite == "") {
			if (board[y][x] == 'O') {
				opposite += alp;
				opposite += to_string(y + 1);
				break;
			}
			x++;
			y++;
			alp++;
			if (x < N && y < N) {
				if (board[y][x] == '.' || board[y][x] == '#') break;
			}
		}
	}
	else { // X's round
		while (x <= N - 1 && y <= N - 1 && opposite == "") { 
			if (board[y][x] == 'X') {
				opposite += alp;
				opposite += to_string(y + 1);
				break;
			}
			x++;
			y++;
			alp++;
			if (x < N && y < N) {
				if (board[y][x] == '.' || board[y][x] == '#') break;
			}
		}
	}

	return opposite;
}

bool validMove(string position, string leftTop, string top, string rightTop, string left,
	string right, string leftBottom, string bottom, string rightBottom) { // check if a move is valid
	bool ok1 = 1, ok2 = 1, ok3 = 1, ok4 = 1, ok5 = 1, ok6 = 1, ok7 = 1, ok8 = 1;
	int x, y, a, b;
	x = toupper(position[0]) - 65;
	y = stoi(position.substr(1)) - 1;

	if (leftTop != "") {
		a = toupper(leftTop[0]) - 65;
		b = stoi(leftTop.substr(1)) - 1;
		if (x - 1 == a && y - 1 == b) ok1 = 0;
	}
	else {
		ok1 = 0;
	}
	if (top != "") {
		a = toupper(top[0]) - 65;
		b = stoi(top.substr(1)) - 1;
		if (y - 1 == b) ok2 = 0;
	}
	else {
		ok2 = 0;
	}
	if (rightTop != "") {
		a = toupper(rightTop[0]) - 65;
		b = stoi(rightTop.substr(1)) - 1;
		if (x + 1 == a && y - 1 == b) ok3 = 0;
	}
	else {
		ok3 = 0;
	}
	if (left != "") {
		a = toupper(left[0]) - 65;
		b = stoi(left.substr(1)) - 1;
		if (x - 1 == a) ok4 = 0;
	}
	else {
		ok4 = 0;
	}
	if (right != "") {
		a = toupper(right[0]) - 65;
		b = stoi(right.substr(1)) - 1;
		if (x + 1 == a) ok5 = 0;
	}
	else {
		ok5 = 0;
	}
	if (leftBottom != "") {
		a = toupper(leftBottom[0]) - 65;
		b = stoi(leftBottom.substr(1)) - 1;
		if (x - 1 == a && y + 1 == b) ok6 = 0;
	}
	else {
		ok6 = 0;
	}
	if (bottom != "") {
		a = toupper(bottom[0]) - 65;
		b = stoi(bottom.substr(1)) - 1;
		if (y + 1 == b) ok7 = 0;
	}
	else {
		ok7 = 0;
	}
	if (rightBottom != "") {
		a = toupper(rightBottom[0]) - 65;
		b = stoi(rightBottom.substr(1)) - 1;
		if (x + 1 == a && y + 1 == b) ok8 = 0;
	}
	else {
		ok8 = 0;
	}
	return (ok1 || ok2 || ok3 || ok4 || ok5 || ok6 || ok7 || ok8);
}

void update(char board[N][N], int round, string position, string leftTop, string top, string rightTop, string left,
	string right, string leftBottom, string bottom, string rightBottom) { // update board state			
	int x, y, a, b; // board[y][x]
	
	if (round % 2 == 0) { // O's round
		if (leftTop != "") {
			x = toupper(position[0]) - 65;
			y = stoi(position.substr(1)) - 1;
			a = toupper(leftTop[0]) - 65;
			b = stoi(leftTop.substr(1)) - 1;
			while (!(x == a && y == b)) {
				board[y][x] = 'O';
				x--;
				y--;
			}
		}
		if (top != "") {
			x = toupper(position[0] - 65);
			y = stoi(position.substr(1)) - 1;
			a = toupper(top[0]) - 65;
			b = stoi(top.substr(1)) - 1;
			while (!(x == a && y == b)) {
				board[y][x] = 'O';
				y--;
			}
		}
		if (rightTop != "") {
			x = toupper(position[0]) - 65;
			y = stoi(position.substr(1)) - 1;
			a = toupper(rightTop[0]) - 65;
			b = stoi(rightTop.substr(1)) - 1;
			while (!(x == a && y == b)) {
				board[y][x] = 'O';
				x++;
				y--;
			}
		}
		if (left != "") {
			x = toupper(position[0]) - 65;
			y = stoi(position.substr(1)) - 1;
			a = toupper(left[0]) - 65;
			b = stoi(left.substr(1)) - 1;
			while (!(x == a && y == b)) {
				board[y][x] = 'O';
				x--;
			}
		}
		if (right != "") {
			x = toupper(position[0]) - 65;
			y = stoi(position.substr(1)) - 1;
			a = toupper(right[0]) - 65;
			b = stoi(right.substr(1)) - 1;
			while (!(x == a && y == b)) {
				board[y][x] = 'O';
				x++;
			}
		}
		if (leftBottom != "") {
			x = toupper(position[0]) - 65;
			y = stoi(position.substr(1)) - 1;
			a = toupper(leftBottom[0]) - 65;
			b = stoi(leftBottom.substr(1)) - 1;
			while (!(x == a && y == b)) {
				board[y][x] = 'O';
				x--;
				y++;
			}
		}
		if (bottom != "") {
			x = toupper(position[0]) - 65;
			y = stoi(position.substr(1)) - 1;
			a = toupper(bottom[0]) - 65;
			b = stoi(bottom.substr(1)) - 1;
			while (!(x == a && y == b)) {
				board[y][x] = 'O';
				y++;
			}
		}
		if (rightBottom != "") {
			x = toupper(position[0]) - 65;
			y = stoi(position.substr(1)) - 1;
			a = toupper(rightBottom[0]) - 65;
			b = stoi(rightBottom.substr(1)) - 1;
			while (!(x == a && y == b)) {
				board[y][x] = 'O';
				x++;
				y++;
			}
		}
	}
	else { // X's round
		if (leftTop != "") {
			x = toupper(position[0]) - 65;
			y = stoi(position.substr(1)) - 1;
			a = toupper(leftTop[0]) - 65;
			b = stoi(leftTop.substr(1)) - 1;
			while (!(x == a && y == b)) {
				board[y][x] = 'X';
				x--;
				y--;
			}
		}
		if (top != "") {
			x = toupper(position[0]) - 65;
			y = stoi(position.substr(1)) - 1;
			a = toupper(top[0]) - 65;
			b = stoi(top.substr(1)) - 1;
			while (!(x == a && y == b)) {
				board[y][x] = 'X';
				y--;
			}
		}
		if (rightTop != "") {
			x = toupper(position[0]) - 65;
			y = stoi(position.substr(1)) - 1;
			a = toupper(rightTop[0]) - 65;
			b = stoi(rightTop.substr(1)) - 1;
			while (!(x == a && y == b)) {
				board[y][x] = 'X';
				x++;
				y--;
			}
		}
		if (left != "") {
			x = toupper(position[0]) - 65;
			y = stoi(position.substr(1)) - 1;
			a = toupper(left[0]) - 65;
			b = stoi(left.substr(1)) - 1;
			while (!(x == a && y == b)) {
				board[y][x] = 'X';
				x--;
			}
		}
		if (right != "") {
			x = toupper(position[0]) - 65;
			y = stoi(position.substr(1)) - 1;
			a = toupper(right[0]) - 65;
			b = stoi(right.substr(1)) - 1;
			while (!(x == a && y == b)) {
				board[y][x] = 'X';
				x++;
			}
		}
		if (leftBottom != "") {
			x = toupper(position[0]) - 65;
			y = stoi(position.substr(1)) - 1;
			a = toupper(leftBottom[0]) - 65;
			b = stoi(leftBottom.substr(1)) - 1;
			while (!(x == a && y == b)) {
				board[y][x] = 'X';
				x--;
				y++;
			}
		}
		if (bottom != "") {
			x = toupper(position[0]) - 65;
			y = stoi(position.substr(1)) - 1;
			a = toupper(bottom[0]) - 65;
			b = stoi(bottom.substr(1)) - 1;
			while (!(x == a && y == b)) {
				board[y][x] = 'X';
				y++;
			}
		}
		if (rightBottom != "") {
			x = toupper(position[0]) - 65;
			y = stoi(position.substr(1)) - 1;
			a = toupper(rightBottom[0]) - 65;
			b = stoi(rightBottom.substr(1)) - 1;
			while (!(x == a && y == b)) {
				board[y][x] = 'X';
				x++;
				y++;
			}
		}
	}
}

bool checkPass(char board[N][N], int round) {
	bool passing = 1;
	string leftTop, top, rightTop, left, right, leftBottom, bottom, rightBottom;

	for (char c = 'A'; c < 'A' + N; c++) {
		for (int j = 0; j < N; j++) {
			string pos = "";
			if (board[j][c - 65] != '.') continue;
			pos += c;
			pos += to_string(j + 1);
			leftTop = FindleftTop(board, round, pos);
			top = FindTop(board, round, pos);
			rightTop = FindrightTop(board, round, pos);
			left = FindLeft(board, round, pos);
			right = FindRight(board, round, pos);
			leftBottom = FindleftBottom(board, round, pos);
			bottom = FindBottom(board, round, pos);
			rightBottom = FindrightBottom(board, round, pos);
			if (validMove(pos, leftTop, top, rightTop, left, right, leftBottom, bottom, rightBottom) == 1) passing = 0;
		}
	}
	return passing;
}

int countBlack(char board[N][N]) {
	int count = 0;
	for (int i = 0; i <= N - 1; i++) {
		for (int j = 0; j <= N - 1; j++) {
			if (board[j][i] == 'X') count++;
		}
	}
	return count;
}

int countWhite(char board[N][N]) {
	int count = 0;
	for (int i = 0; i <= N - 1; i++) {
		for (int j = 0; j <= N - 1; j++) {
			if (board[j][i] == 'O') count++;
		}
	}
	return count;
}

int main() {
	char board[N][N];
	int pits; // number of pits
	int max = (N * N) / 2; // maximum number of pits
	int round = 1; // number of rounds
	string position; // user input position
	int pass = 0; // number of consecutive passes
	int black = 0, white = 0; // number of pieces
	bool ok = 1;
	string leftTop = "", top = "", rightTop = "", left = "", right = "", leftBottom = "", bottom = "", rightBottom = ""; // position of opposite same color piece from user input

	do { // ask for number of pits
		cout << "Enter number of pits: ";
		cin >> pits;
		if (pits > max) cout << "Too many pits!" << endl;
		if (pits < 0) cout << "Number of pits cannot be smaller than 0!" << endl;
	} while (pits > max || pits < 0);

	initial(board);

	addPits(board, pits);

	do { // main game
		cout << "Round " << round << ":" << endl;
		printBoard(board);
		if (checkPass(board, round) == 1) { // passing situation
			if (round % 2 == 0) cout << "Player O has no valid moves! Pass!" << endl;
			else cout << "Player X has no valid moves! Pass!" << endl;
			pass++;
			round++;
		}
		else { // normal round
			do { // validate user input
				ok = 1;
				pass = 0;
				cout << "Player ";
				if (round % 2 == 0) cout << "O's turn: ";
				else cout << "X's turn: ";
				cin >> position;
				position[0] = toupper(position[0]);
				leftTop = FindleftTop(board, round, position);
				top = FindTop(board, round, position);
				rightTop = FindrightTop(board, round, position);
				left = FindLeft(board, round, position);
				right = FindRight(board, round, position);
				leftBottom = FindleftBottom(board, round, position);
				bottom = FindBottom(board, round, position);
				rightBottom = FindrightBottom(board, round, position);
				if (validMove(position, leftTop, top, rightTop, left, right, leftBottom, bottom, rightBottom) == 0) ok = 0;
				if (!(ok)) cout << "Invalid move!" << endl;
			} while (!(ok));
			update(board, round, position, leftTop, top, rightTop, left, right, leftBottom, bottom, rightBottom);
			round++;
		}
	} while (pass < 2);

	black = countBlack(board);
	white = countWhite(board);
	cout << "Game over:" << endl;
	printBoard(board);
	if (black == white) cout << "Draw game!";
	if (black > white) cout << "Player X wins!";
	if (black < white) cout << "Player O wins!";

	return 0;
}