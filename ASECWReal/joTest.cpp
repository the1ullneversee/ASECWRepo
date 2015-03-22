#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <cmath>
#include <map>
#include <string>
#include <iterator>
#include <sstream>

//#include "joACBC.cpp"
//#include "joVect.cpp"





using namespace std;

//const unsigned int repeat = 1;


std::vector<unsigned int> joACBC(unsigned int n, unsigned int m);
std::vector<unsigned int> joVect(unsigned int n, unsigned int m);

template <typename T>
std::ostream & operator<<(ostream & out, const vector<T> & vt)
{
	typename std::vector<T>::const_iterator vtci = vt.cbegin();
	out << '[' ;
	if (vtci != vt.end())
	{
		out << *vtci;
		++vtci;
		while (vtci != vt.end())
		{
			out << ", " << *vtci;
			++vtci;
		}
	}
	out << ']';
	return out;
}

template <typename T>
string toString(const vector<T> & vt)
{
	ostringstream oss;
	typename std::vector<T>::const_iterator vtci = vt.cbegin();
	oss << "< " ;
	if (vtci != vt.end())
	{
		oss << *vtci;
		++vtci;
		while (vtci != vt.end())
		{
			oss << " " << *vtci;
			++vtci;
		}
	}
	oss << " >";
	return oss.str();
}

unsigned parseInt(const string & intSt) 
{
	istringstream iss(intSt);
	unsigned x;
	iss >> x;
	return x;
}



bool parseSwitch(const string & swSt, pair<char, string> & result) 
{
	if ((swSt == "--h") || (swSt == "--d"))
	{
		result = make_pair(swSt[2], "true");
		return true;
	}
	string switches = "mnfr"; 
	string value;
	bool okaySoFar = true;
	okaySoFar = 
		(swSt.length() > 2) &&
		(swSt.substr(0,2) == "--") &&
		(switches.find(swSt[2]) != string::npos) &&
		(swSt[3] == '=');
	if (okaySoFar) 	
	{
		value = swSt.substr(4);
		result = make_pair(swSt[2], value);
	}
	else 
	{
		result = make_pair('e', "switch parse error");
	}
	return okaySoFar;
}





map<char, string> parseArgs(const vector<string> & args) 
{
	map<char, string> resMap;
	pair<char,string> switchVal;
	bool argsWillExecute = true;
	bool thisOneOkay;
	for (string st : args) {
		thisOneOkay = parseSwitch(st, switchVal);
		argsWillExecute=argsWillExecute && thisOneOkay;
		if (thisOneOkay) 
		{
			resMap.insert(switchVal);
		}
		else 
		{
			resMap['e'].append(string(" - problem with ").append(st));
		}
	}
	return resMap;
}


string getValFromUser(std::string varName)
{
	std::string line;
	cout << endl << "Please enter your value for " << varName << ' ';
	cin >> line;
	return line;
}

void man()
{

}

int main(int argv, char* argc[])

{
	std::vector<std::string> args;
	std::map<char, std::string> mapp;
	unsigned repeats = 1;
	unsigned n, m;
	for (int i=1; i<argv; ++i) 
	{
		args.push_back(string(argc[i]));
		cout << endl << args.back();
	}

	if (argv==1) 
	{
		mapp['n'] = getValFromUser("n");
		mapp['m'] = getValFromUser("m");
	}
	else 
		mapp = parseArgs(args);
	if  (mapp['h'] == "true")
	{
		man();
	}
	else 
	{
		if (mapp['e'].empty()) 
		{
			std::string reps = mapp['r'];
			repeats = ((reps=="") || (!mapp['f'].empty())) ? 1 : parseInt(reps);
			n = parseInt(mapp['n'].empty() ? getValFromUser("n") : mapp['n']);
			m = parseInt(mapp['m'].empty() ? getValFromUser("m") : mapp['m']);

			auto phaseStart = std::chrono::steady_clock::now();
			for (unsigned int r=0; r < repeats; ++r); 
			std::vector<unsigned int> answer = joVect(n, m);
			if (mapp['d']!="no")
				setvbuf(stdout, 0, _IOLBF, BUFSIZ);
				std::cout << endl << "Call:  joACBC(" << n <<','<< m <<')' << endl << "returned "<< toString(answer) << std::endl;
			auto phaseEnd = std::chrono::steady_clock::now();
			auto phaseElapsed = std::chrono::duration_cast<std::chrono::microseconds>(phaseEnd - phaseStart);
			std::cout << "Call(s) elapsed time : " << float(phaseElapsed.count()/1E6) << std::endl;
			std::string fn = mapp['f'];
			if (!fn.empty())
			{
				ofstream out(fn.c_str());
				out << toString(answer);
				out.close();
			}
		}
		else
			std::cout << endl << mapp['e'].substr(5) << endl;
	}

}
