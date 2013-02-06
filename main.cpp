/*
 * main.cpp
 *
 *  Created on: Feb 4, 2013
 *      Author: Alex
 *
 *
 *
 *      integer values are ordinal
 *
 *      decimal values are continuous
 *
 *      all else is categorical (distance of 1 or 0)
 *
 *
 */


#include<iostream>
#include<fstream>
#include<string>
#include<cmath>

using namespace std;

double find_distance(string,string);
double sub_distance(string,string);
int isint(string);


void test(){
	string test_string1 = "poop";
	string test_string2 = "gayeeee!!!";

	//TESTING LOOP FOR sub_distance(string,string);
	while (test_string1 != "q"){
		cout << "\nPlease enter strings for distance test\n";
		cin >> test_string1 >> test_string2;
		cout << endl <<sub_distance(test_string1, test_string2) << endl;
	}
	//End Loop

//TESTING LOOP for isint(string)
//		while (test_string1 != "q"){
//			cout << "\nPlease enter strings for isint() test\n";
//			cin >> test_string1;
//			cout << endl << isint(test_string1) << endl;
//		}
	return;
}


int main()
{
	ifstream fin;
	ofstream fout;

	string temp_instance;
	string instances[10000];
	string input;

	double dist = 0;
	int i = 0;


	fin.open("test.txt");

//this is where we will input training data
	fin >> temp_instance;

test();

	while(!fin.eof()){

		fin >> instances[i];
		cout << "original string:\n" << instances[i] << endl;

		dist = find_distance(instances[i], temp_instance);
	}

	fin.close();

}


double find_distance(string instance, string compare)
{

	string instance_sub, compare_sub;
	int pos1 = 0, pos2 = 0;
	int prev_pos1 = 0, prev_pos2 = 0;
	double dist = 0.0;

	cout << "attempting to remove all commas: \n";

	while ( pos1 != -1 && pos2 != -1){

			pos1 = -1;
			pos2 = -1;

			pos1 = instance.find(',', prev_pos1 + 1);
			pos2 = compare.find(',', prev_pos2 + 1);

			instance_sub = instance.substr(prev_pos1 + 1, pos1 - (prev_pos1 + 1));
			compare_sub = compare.substr(prev_pos2 + 1, pos2 - (prev_pos2 + 1));

			//dist += sub_distance(instance_sub, compare_sub);

			prev_pos1 = pos1;
			prev_pos2 = pos2;

	}

	return dist;
}


double sub_distance(string instance_sub, string compare_sub)
{
	double sub_distance = 0.0;

//For nominal data
	if( isalpha(instance_sub[0]) && isalpha(compare_sub[0]) ){

		//if they are not equal they are 1 apart
		if(instance_sub != compare_sub)
			return 1;
		else
			return 0;
	}else if(isint(instance_sub) && isint(compare_sub)){

		return abs( atoi(instance_sub.c_str()) - atoi(compare_sub.c_str()) );

	}else if (!isint(instance_sub) && !isint(compare_sub)){

		double result = abs( (strtod(instance_sub.c_str(), NULL) - strtod(compare_sub.c_str(), NULL) ) );
		cout << endl << "comparing doubles" << strtod(instance_sub.c_str(), NULL) << " and " <<strtod(compare_sub.c_str(), NULL) << endl;
		cout << "result: " << result << endl;
		return result;

	}

//For ordinal data


	return sub_distance;

}

//tested and it WORKS
int isint(string test){

	if(test.find('.') == -1)
		return 1;
	else return 0;
}




