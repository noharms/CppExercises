#pragma once


void ElementsOfProgrammingChapter04PrimitiveTypes();

void ElementsOfProgrammingChapter04PrimitiveTypes_UnsetLowestSetBit(unsigned int number);

void ElementsOfProgrammingChapter04PrimitiveTypes_ComputeParityPerDefinition(unsigned int number);
void ElementsOfProgrammingChapter04PrimitiveTypes_ComputeParityUsingLowestSetBit(unsigned int number);
void ElementsOfProgrammingChapter04PrimitiveTypes_ComputeParityUsingLookupTable(unsigned int number);
void ElementsOfProgrammingChapter04PrimitiveTypes_ComputeParityUsingDivideAndConquer(unsigned int number);

int UnsetLowestSetBit(unsigned int  num);

bool ComputeParityPerDefinition(unsigned int num);

bool ComputeParityUsingUnsetLowestSetBit(unsigned int  num);

bool ComputeParityUsingLookUpTable(unsigned int  num);

bool ComputeParityUsingDivideAndConquer(unsigned int num, int n_bits_considered);

void PrintIntegerAsBitField(unsigned int  num);
