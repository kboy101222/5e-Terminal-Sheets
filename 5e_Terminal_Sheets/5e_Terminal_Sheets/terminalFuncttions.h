; // WHY DOES THIS DO ANYHTING?????

using namespace std;

int getCenterSize(string text);
int getSize(string type);
int choiceIn(vector<string> file, string alignment);
void clearLine(char fillChar, int linesAbove); 
void newLine(int lines);

int choiceIn(vector<string> file, string alignment = "left"){ // Takes a vector of options and allows the user to scroll through the list, returning the index of their choice
	vector<string>::size_type scroll = 0;

	for (;;) {
		cout << '\r';
		cout << setw(50) << setfill(' ') << " ";
		cout << '\r';
		if (alignment == "left"){
			cout << file[scroll];
		}
		else if (alignment == "center"){
			cout << setw(getCenterSize(file[scroll])) << file[scroll];
		}

		int ch = _getch();
		if (ch == 0 || ch == 224)
		{
			switch (_getch())
			{
			case 72:
				if (scroll > 0)
					scroll--;
				break;

			case 80:
				if (scroll < file.size() - 1)
					scroll++;
				break;
			}
		}
		else if (ch == '\r' || ch == '\n'){
			cout << "\n";
			return scroll;
		}
	}
}

int getCenterSize(string text){ // Gets the first printing location in order to center text of X size
	if (text.size() <= getSize("columns")){
		return ((getSize("columns") / 2) + (text.length() / 2)) - 1;
	}
	else {
		return 0;
	}
}

int getSize(string type){ // Gets the width or height of the console (WINDOWS ONLY)
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	int columns, rows;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

	if (type == "rows"){
		return rows;
	}
	else {
		return columns;
	}
}

int getLines(string file){ // Gets the # of lines inside a text file
	ifstream LoadFile;
	string line;
	int totalLines = 0;

	LoadFile.open(file);

	while (getline(LoadFile, line)){
		totalLines++;
	}

	LoadFile.close();
	return totalLines;
}

void clearLine(char fillChar, int linesAbove = 0){ // Clears the current line and moves the cursor to the beginning
	if (linesAbove == 0){
		cout << setw(getSize("columns")) << setfill(fillChar) << " ";
		cout << '\r';
	}
	else if (linesAbove > 0){
		for (int i = 0; i < linesAbove; i++){

		}
	}
}

void newLine(int lines){ // Creates as many new lines as needed for formatting
	for (int i = 0; i < lines; i++){
		cout << endl;
	}
}