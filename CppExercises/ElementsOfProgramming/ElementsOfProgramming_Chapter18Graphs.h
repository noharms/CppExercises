#pragma once

#include <array>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <list>

void ElementsOfProgrammingChapter18Graphs();

void ElementsOfProgrammingChapter18Graphs_ExerciseWinReachability();

bool FindWinningPath(
	std::unordered_map<std::string, std::unordered_set<std::string>>& graph,
	std::string teamA,
	std::string teamB,
	std::list<std::string>& path);


bool GraphDFS(
	std::unordered_map<std::string, std::unordered_set<std::string>>& graph,
	std::string base,
	std::string target,
	std::list<std::string>& path,
	std::unordered_set<std::string>& visited_nodes);