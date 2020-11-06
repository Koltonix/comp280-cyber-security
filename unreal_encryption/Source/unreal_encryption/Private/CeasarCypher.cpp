// Fill out your copyright notice in the Description page of Project Settings.


#include "CeasarCypher.h"

#include <numeric>
#include <vector>
#include <map>

using namespace std;

CeasarCypher::CeasarCypher()
{
	m_shiftedAlphabet = GetShiftedAlphabet(5);
}

CeasarCypher::~CeasarCypher()
{
}

char* CeasarCypher::EncryptText(char* text)
{
	for (int i = 0; i < (sizeof(text)/sizeof(text[0])); i++)
		

	return nullptr;
}

map<char, char> CeasarCypher::GetShiftedAlphabet(int key)
{
	// Sanity check
	key = key > 26 ? 26 : key;
	key = key < 0 ? 0 : key;
	
	vector<char> alphabet(26);
	iota(alphabet.begin(), alphabet.end(), 'a');

	vector<char> shifted_alphabet = vector<char>();
	map<char, char> conversion_map = map<char, char>();

	// Source: https://stackoverflow.com/questions/49210366/vector-initialization-in-cpp
	int start_index = (alphabet.size() - key);
	FString concatenated_shifted = "";

	// Adds the shifted values first
	for (int i = start_index; i < alphabet.size(); i++)
	{
		shifted_alphabet.push_back(alphabet[i]);
		concatenated_shifted += alphabet[i];
	}

	// Adds the rest of the alphabet back in without the shiften values
	for (int i = 0; i < alphabet.size() - key; i++)
	{
		shifted_alphabet.push_back(alphabet[i]);
		concatenated_shifted += alphabet[i];
	}
	
	// Assigns it to a map
	for (int i = 0; i < shifted_alphabet.size(); i++)
		conversion_map.emplace(alphabet[i], shifted_alphabet[i]);

	return conversion_map;
}
