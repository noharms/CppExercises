
#include "pch.h"

#include "ElementsOfProgramming_Chapter18Graphs.h"

#include <iostream>



typedef std::string std_str;
typedef std::unordered_map<std::string, std::unordered_set<std::string>> hashmap_team2beatenteams;

void ElementsOfProgrammingChapter18Graphs() {

	std::cout << "-- Entering ElementsOfProgrammingChapter18Graphs " << std::endl;

	//--------- Exercise: Win Reachability From Team A to Team B
	ElementsOfProgrammingChapter18Graphs_ExerciseWinReachability();

	return;
}


/**
 *----------------------------------------------------------------------------------------------
 *----------------------------------------------------------------------------------------------
 *----------------------------------------------------------------------------------------------
*/

/*
	Given a set of teams and matches between the teams with the information which
	team has won the match, one can build a directed graph with the teams being the nodes
	and an directed edge representing a win from the source over the target of the edge

	task: check if there exists a winning relation from a given team X to another given team Y

	-> this directly translates to: is team Y node reachable from team X node , or
	   is there a path from team X node to team Y node

*/
void ElementsOfProgrammingChapter18Graphs_ExerciseWinReachability() {

	std::vector<std::string> teams;
	teams.emplace_back("Bayern");
	teams.emplace_back("Dortmund");
	teams.emplace_back("Leipzig");
	teams.emplace_back("Schalke");
	teams.emplace_back("Hoffenheim");
	teams.emplace_back("Leverkusen");

	std::unordered_map<std::string, std::unordered_set<std::string>> win_graph;
	win_graph["Bayern"] = {};
	win_graph["Bayern"] = { "Dortmund", "Leipzig", "Schalke", "Hoffenheim", "Leverkusen" };
	win_graph["Dortmund"] = {};
	win_graph["Dortmund"] = { "Hoffenheim", "Leverkusen" };
	win_graph["Leipzig"] = {};
	win_graph["Leipzig"] = { "Dortmund", "Bayern" };
	win_graph["Schalke"] = {};
	win_graph["Schalke"] = { "Dortmund" };
	win_graph["Hoffenheim"] = {};
	win_graph["Hoffenheim"] = { "Leipzig", "Schalke"};
	win_graph["Leverkusen"] = {};
	win_graph["Leverkusen"] = { "Schalke" };

	std::cout << "Starting the search." << std::endl;

	std::list<std::string> winning_path;
	const std::string start_node = "Schalke";
	const std::string target_node = "Bayern";
	bool isreachable = FindWinningPath(win_graph, start_node, target_node, winning_path);
	
	std::cout << "Search was " << (isreachable ? "successfull" : "not successfull") << std::endl;
	std::string prev_node = start_node;
	if (isreachable) {
		std::cout << "The following path was found from " << start_node << " to " << target_node << " (note: there may be other paths): " << std::endl;
		for (auto it = winning_path.begin(); it != winning_path.end(); ++it) {
			std::cout << "From node " << prev_node << " the path goes to " << *it << std::endl;
			prev_node = *it;
		}
	}

	return;
}



/**
 *----------------------------------------------------------------------------------------------
 *----------------------------------------------------------------------------------------------
 *----------------------------------------------------------------------------------------------
*/

bool FindWinningPath(
	std::unordered_map<std::string, std::unordered_set<std::string>>& graph,
	std::string teamA, 
	std::string teamB,
	std::list<std::string>& path) {
	
	// use a depth first search approach
	std::unordered_set<std::string> visited_nodes;
	bool isreachable = GraphDFS(graph, teamA, teamB, path, visited_nodes);

	return isreachable;
}

/**
* Does not necessarily find the shortest path because it goes down the graph until it reaches the target.
*
*
*/

bool GraphDFS(
	std::unordered_map<std::string, std::unordered_set<std::string>>& graph, 
	std::string base, 
	std::string target, 
	std::list<std::string>& path,
	std::unordered_set<std::string>& visited_nodes) {
	
	// go through all nodes that are reachable from base
	auto beaten_teams = graph[base];
	bool target_visited = false;
	for (auto it = beaten_teams.begin(); it != beaten_teams.end(); ++it) {
		auto curr_node = *it;
		if (visited_nodes.find(curr_node) != visited_nodes.end()) { // if node was visited before, continue
			continue;
		}
		else {
			path.push_back(curr_node); // will be removed if we won't be able to reach target from here
			visited_nodes.insert(curr_node);
			if (curr_node == target) {
				// we have indeed reached the target node
				target_visited = true;
				break;
			}
			else {
				target_visited = GraphDFS(graph, curr_node, target, path, visited_nodes);
				if (target_visited) {
					break;
				}
				else {
					auto it_to_last_elem = std::prev(path.end());
					path.erase(it_to_last_elem);
				}
			}
		}		
	}

	return target_visited;
}
