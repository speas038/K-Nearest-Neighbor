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

using namespace std;

double find_distance(string,string);
double distance(string,string);

int main()
{


	ifstream fin;
	ofstream fout;

	string temp_instance;
	string instances[10000];

	double distance = 0;
	int i = 0;


	fin.open("test.txt");

	fin >> temp_instance;


	while(!fin.eof()){

		fin >> instances[i];
		cout << "original string:\n" << instances[i] << endl;

		distance = find_distance(instances[i], temp_instance);
	}

	fin.close();

}


double find_distance(string instance, string compare)
{

	string instance_sub, compare_sub;
	int pos1 = 0, pos2 = 0;
	int prev_pos1 = 0, prev_pos2 =0;
	int distance = 0;

	cout << "attempting to remove all commas: \n";

	while ( pos1 != -1 && pos2 != -1){

			pos1 = -1;
			pos2 = -1;

			pos1 = instance.find(',', prev_pos1 + 1);
			pos2 = compare.find(',', prev_pos2 + 1);

			instance_sub = instance.substr(prev_pos1 + 1, pos1 - (prev_pos1 + 1));
			compare_sub = compare.substr(prev_pos2 + 1, pos2 - (prev_pos2 + 1));

			distance += distance(instance_sub, compare_sub);

			prev_pos1 = pos1;
			prev_pos2 = pos2;

	}

	return distance;
}


double distance(string instance_sub, string compare_sub)
{
	double sub_distance = 0;

	if(isalpha(instance_sub[0]) )


	return sub_distance;
}







