//////////////////////////////////////////////////
// Christopher Robertson 2020.
// https://github.com/Koltonix
// Copyright (c) 2020. All rights reserved.
//////////////////////////////////////////////////

#include "CeasarCypher.h"

#include <numeric>
#include <vector>
#include <map>

using namespace std;

CeasarCypher::CeasarCypher()
{
	FString encrypted = EncryptText(m_shiftKey, m_textToEncrypt);
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, encrypted);
	FString decrypted = DecryptText(m_shiftKey, encrypted);
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, "\n" + decrypted);

	map<char, char> shifted_cypher = GetShiftedAlphabet(m_shiftKey);
	PrintShiftedCypher(shifted_cypher);
}

CeasarCypher::~CeasarCypher()
{
}

FString CeasarCypher::EncryptText(int key, FString text)
{
	// This encryption does not support upper case
	text = text.ToLower();

	map<char, char>cypher = GetShiftedAlphabet(key);
	FString encrypted_text = "";

	// Encryption
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

FString CeasarCypher::DecryptText(int key, FString encryptedText)
{
	// This encryption does not support upper case
	encryptedText = encryptedText.ToLower();

	map<char, char>cypher = GetShiftedAlphabet(key);
	FString decrypted_text = "";

	// Inverting the map
	map<char, char> i_cypher;
	for (pair<char, char> e : cypher)
		i_cypher.emplace(e.second, e.first);

	// Decryption
	for (int i = 0; i < encryptedText.Len(); i++)
	{
		// Key not in the alphabet
		if (i_cypher.find(encryptedText[i]) == i_cypher.end())
			decrypted_text += encryptedText[i];

		else
			decrypted_text += i_cypher[encryptedText[i]];
	}

	return decrypted_text;
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
	
	// Shifting alphabet
	for (int i = 0; i < key; i++)
	{
		// Inserting the last element first and then removing the last element
		encrypted_alphabet.insert(encrypted_alphabet.begin(), encrypted_alphabet[encrypted_alphabet.size() - 1]);
		encrypted_alphabet.erase(encrypted_alphabet.begin() + (encrypted_alphabet.size() - 1));
	}
	
	// Assigning it to a map for ease of access
	map<char, char> cypher_map = map<char, char>();
	for (int i = 0; i < alphabet.size(); i++)
		cypher_map.emplace(alphabet[i], encrypted_alphabet[i]);

	return cypher_map;
}

void CeasarCypher::PrintShiftedCypher(std::map<char, char> shiftedCypher)
{
	FString concatenated_alphabet = "";
	FString concatenated_cypher = "";

	for (pair<char, char> e : shiftedCypher)
	{
		concatenated_alphabet += e.first;
		concatenated_cypher += e.second;
	}

	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, concatenated_cypher);
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, concatenated_alphabet);
}
