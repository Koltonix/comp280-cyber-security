// Fill out your copyright notice in the Description page of Project Settings.


#include "CeasarCypher.h"

#include <numeric>
#include <vector>
#include <map>

using namespace std;

CeasarCypher::CeasarCypher()
{
	FString encrypted = EncryptText(3, m_textToEncrypt);
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, encrypted);
}

CeasarCypher::~CeasarCypher()
{
}

FString CeasarCypher::EncryptText(int key, FString text)
{
	map<char, char>cypher = GetShiftedAlphabet(key);
	//[a = c]
	FString encrypted_text = "";
	for (int i = 0; i < text.Len(); i++)
	{
		// Key not in the alphabet
		if (cypher.find(text[i]) == cypher.end())
			encrypted_text += text[i];

		else
			encrypted_text += cypher[text[i]];
	}
		

	return encrypted_text;
}

FString CeasarCypher::DecryptText(int key, FString text)
{
	return FString();
}


map<char, char> CeasarCypher::GetShiftedAlphabet(int key)
{
	// Sanity check
	key = (key < 0) ? 0 : key;

	vector<char> alphabet(26);
	vector<char> encrypted_alphabet(26);

	// Source: https://stackoverflow.com/questions/49210366/vector-initialization-in-cpp
	iota(alphabet.begin(), alphabet.end(), 'a');
	encrypted_alphabet = alphabet;
	

	for (int i = 0; i < key; i++)
	{
		// Inserting the last element first and then removing the last element
		encrypted_alphabet.insert(encrypted_alphabet.begin(), encrypted_alphabet[encrypted_alphabet.size() - 1]);
		encrypted_alphabet.erase(encrypted_alphabet.begin() + (encrypted_alphabet.size() - 1));
	}
	
	// Assigning it to a map for ease of access
	map<char, char> cypher_map = map<char, char>();
	FString concatenated_shifted = "";
	for (int i = 0; i < alphabet.size(); i++)
	{
		concatenated_shifted += encrypted_alphabet[i];
		cypher_map.emplace(alphabet[i], encrypted_alphabet[i]);
	}


	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, concatenated_shifted);
	}

	return cypher_map;
}
