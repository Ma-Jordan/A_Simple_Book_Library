#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

class Book
{
private:
	string title, auth, pub, date, cat;
public:
	Book();
	string getT();
	void setT(string);
	string getA();
	void setA(string);
	string getP();
	void setP(string);
	string getD();
	void setD(string);
	string getC();
	void setC(string);
};


int main()
{
	//The initialized list provided by book.txt file
	string data[][5] ={ {"A Breath of Snow and Ashes","Diana Gabaldon","Delacorte","10/16/2005","Fiction"},
  {"A Common Life","Jan Karon","Viking","4/29/2001","Fiction"},
  {"A Dance With Dragons","George R. R. Martin","Bantam","7/31/2011","Non Fiction"},
  {"A Day Late and a Dollar Short","Terry McMillan","Viking","2/4/2001","Fiction"},
  {"A Feast For Crows","George R. R. Martin","Bantam","11/27/2005","Fiction"},
  {"A Lion Is In the Streets","Adria Locke Langley","McGraw","7/1/1945","Non Fiction"},
  {"A Man In Full","Tom Wolfe","Farrar","11/22/1998","Fiction"},
  {"A Painted House","John Grisham","Doubleday","2/25/2001","Non Fiction"},
  {"A Perfect Spy","John le Carre","Knopf","5/4/1986","Fiction"},
  {"A Rage to Live","John O'Hara","Random House","9/18/1949","Fiction"},
  {"A Shade of Difference","Allen Drury","Doubleday","10/28/1962","Non Fiction"},
  {"A Thousand Splendid Suns","Khaled Hosseini","Riverhead","6/10/2007","Fiction"},
  {"A Tree Grows In Brooklyn","Betty Smith","Harper","1/2/1944","Fiction"},
  {"A Widow For One Year","John Irving","Random House","6/14/1998","Non Fiction"},
  {"Accident","Danielle Steel","Delacorte","2/27/1994","Fiction"},
  {"Acheron","Sherrilyn Kenyon","St. Martin's","8/24/2008","Non Fiction"},
  {"Across the River and Into the Trees","Ernest Hemingway","Scribner's","10/15/1950","Fiction"},
  {"Advise and Consent","Allen Drury","Doubleday","10/4/1959","Non Fiction"},
  {"Against All Enemies","Tom Clancy","Putnam","7/3/2011","Non Fiction"},
  {"Airframe","Michael Crichton","Knopf","12/29/1996","Fiction"},
  {"Airport","Arthur Hailey","Doubleday","4/7/1968","Non Fiction"},
  {"Alaska","James Michener","Random House","7/3/1988","Fiction"},
  {"Alex Cross's Trial","James Patterson","Brown","9/13/2009","Non Fiction"},
  {"American Assassin","Vince Flynn","Atria","10/31/2010","Fiction"},
  {"An Indecent Obsession","Colleen McCullough","Harper","11/15/1981","Fiction"},
  {"Anansi Boys","Neil Gaiman","Morrow","10/9/2005","Fiction"},
  {"Anathem","Neal Stephenson","William Morrow","9/28/2008","Fiction"},
  {"Anatomy of a Murder","Robert Traver","St. Martin's","3/9/1958","Non Fiction"},
  {"And Now Tomorrow","Rachel Field","MacMillan","8/9/1942","Non Fiction"},
  {"Andersonville","McKinley Kantor","World Publishing","1/1/1956","Fiction"},
  {"Angels Fall","Nora Roberts","Putnam","7/30/2006","Fiction"},
  {"Answered Prayers","Danielle Steel","Delacorte","11/17/2002","Fiction"},
  {"Arch of Triumph","Erich Maria Remarque","Appleton-Century","3/10/1946","Fiction"},
  {"Armageddon","Tim LaHaye","Tyndale","4/27/2003","Fiction"},
  {"At First Sight","Nicholas Sparks","Warner","11/6/2005","Non Fiction"},
  {"Bad Moon Rising","Sherrilyn Kenyon","St. Martin's","8/23/2009","Non Fiction"},
  {"Bag of Bones","Stephen King","Scribner","10/11/1998","Non Fiction"},
  {"Beach Music","Pat Conroy","Talese/Doubleday","7/16/1995","Fiction"},
  {"Before I Say Goodbye","Mary Higgins Clark","Simon & Schuster","5/7/2000","Fiction"},
  {"Best Friends Forever","Jennifer Weiner","Atria","8/2/2009","Fiction"} };
	//choice for switch cases and slen is for string length
	int choice,slen;
	string cata, name, hold, year1, year2, hold2;
	//my 40 objects are created and initialized to ""
	Book cache[40];
	bool go = true, found = false;
	//This loop fills the 40 objects with the proper data using mutator functions
	for (int i = 0; i < 40; i++)
	{
		cache[i].setT(data[i][0]);
		cache[i].setA(data[i][1]);
		cache[i].setP(data[i][2]);
		cache[i].setD(data[i][3]);
		cache[i].setC(data[i][4]);
	}
	//DISPLAYS CACHE
	/*for (int i = 0; i < 40; i++)
	{
		cout << cache[i].getT() << " "<<cache[i].getA() << " "<< cache[i].getP() << " "<< cache[i].getD() << " "<<cache[i].getC()<<endl;
	}*/
	//Menu for switch cases
	while (go)
	{
		cout << "Menu:\n" << endl;
		cout << "1. Display all books in a year range.\n\n";
		cout << "2. Search for an author.\n\n";
		cout << "3. Display all books for a category.\n\n";
		cout << "4. Display entire library.\n\n";
		cout << "5. Quit\n\n";
		found = false;
		//Error check for char or integer input
		if (cin >> choice)
		{
		}
		else
		{
			choice = 0;
			cin.clear();
		}
		cin.ignore();
		switch (choice)
		{
		case 1: cout << "Enter the starting year: ";
			getline(cin, year1);
			cout << "\nEnter the ending year: ";
			getline(cin, year2);
			cout << endl;
			//This loop dissects the date string
			//Since the last 4 characters are always the year
			//I concatenate accordingly and use it to compare user input
			cout << "\nThe titles in that year range are:\n\n";
			for (int i = 0; i < 40; i++)
			{
				hold = cache[i].getD();
				slen = hold.length();
				hold2 = hold[slen - 4];
				hold2 += hold[slen - 3];
				hold2 += hold[slen - 2];
				hold2 += hold[slen - 1];

				if (hold2>=year1 && hold2 <= year2)
				{
					found = true;
					cout << cache[i].getT() << ". by "<< cache[i].getA()<< endl;
				}
			}
			if (found == false)
			{
				cout << "\nThere were no books found in that range.\n";
			}
			cout << endl;
			break;
		case 2: cout << "Enter the author's name: ";
			getline(cin, name);
			//I use getline to get author's full name
			//This function from algorithms goes through an entire string
			//and converts each character to lower case
			for_each(name.begin(), name.end(), [](char& c)
				{
					c = ::tolower(c);
				});
			cout << "\nThe titles from that author are: \n\n";
			//This loop goes through all 40 objects to see if the name matches
			//If there is a match the title and author accessor functions are called
			for (int i = 0; i < 40; i++)
			{
				hold = cache[i].getA();
				for_each(hold.begin(), hold.end(), [](char& c)
					{
						c = ::tolower(c);
					});
				if (name == hold)
				{
					cout << cache[i].getT() << ". by " << cache[i].getA() << endl;
					found = true;
				}
			}
			if (found == false)
			{
				cout << "There were no titles from that author.\n\n";
				break;
			}
			cout << endl << endl;
			break;
		case 3: cout << "Enter a category: ";
			getline(cin,cata);
			//similar to case 2 this function converts case
			for_each(cata.begin(), cata.end(), [](char& c)
				{
					c = ::tolower(c);
				});
			cout << "\nThe titles in that category are: \n\n";
			for (int i = 0; i < 40; i++)
			{
				hold = cache[i].getC();
				for_each(hold.begin(), hold.end(), [](char& c)
					{
						c = ::tolower(c);
					});
				if (cata == hold)
				{
					cout << cache[i].getT() << ". by " << cache[i].getA() << endl;
					found = true;
				}
			}
			if (found == false)
			{
				cout << "There were no titles in that category.\n\n";
			}
			cout << endl << endl;
			break;
		case 4: 
			//This case is to display the library contents
			//It is useful for users to search or view entire library
			for (int i = 0; i < 40; i++)
			{
				cout << cache[i].getT() << ", "<<cache[i].getA() << ", "<< cache[i].getP() << ", "<< cache[i].getD() << ", "<<cache[i].getC()<<endl;
			}
			break;
		case 5: go = false;
			cout << "\nTerminating program.\n\n";
			break;
		default: cout << "Invalid choice, try again.\n\n";
			break;
		}
	}
	return 0;
}
Book::Book()
{
	title = "";
	auth = "";
	pub = "";
	date = "";
	cat = "";
}
string Book::getT()
{
	return title;
}
string Book::getA()
{
	return auth;
}
string Book::getD()
{
	return date;
}
string Book::getC()
{
	return cat;
}
string Book::getP()
{
	return pub;
}
void Book::setT(string word)
{
	title = word;
}
void Book::setA(string word)
{
	auth = word;
}
void Book::setP(string word)
{
	pub = word;
}
void Book::setD(string word)
{
	date = word;
}
void Book::setC(string word)
{
	cat = word;
}