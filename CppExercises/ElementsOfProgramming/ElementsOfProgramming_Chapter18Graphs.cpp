
#include "pch.h"

#include "ElementsOfProgramming_Chapter18Graphs.h"

#include <iostream>
#include <queue>



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
    bool isreachable = false;
    
    //------ try with DFS search
    std::cout << "-- Starting DFS Search " << std::endl;
    isreachable = FindWinningPath(win_graph, start_node, target_node, winning_path, "DFS");	
	std::cout << "DFS Search " << (isreachable ? "found the target" : "did not find the target") << std::endl;
	std::string prev_node = start_node;
	if (isreachable) {
		std::cout << "The following path was found from " << start_node << " to " << target_node << " (note: there may be other paths): " << std::endl;
		for (auto it = winning_path.begin(); it != winning_path.end(); ++it) {
			std::cout << "From node " << prev_node << " the path goes to " << *it << std::endl;
			prev_node = *it;
		}
	}
   
    //------ try with BFS search
    std::cout << "-- Starting BFS Search " << std::endl;
    isreachable = FindWinningPath(win_graph, start_node, target_node, winning_path, "BFS");
    std::cout << "BFS Search " << (isreachable ? "found the target" : "did not find the target") << std::endl;    

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
	std::list<std::string>& path,
    const std::string& search_mode) {
	
	// use a depth first search approach
    bool isreachable = false;
    
    if (search_mode == "DFS") {
        std::unordered_set<std::string> visited_nodes;
        isreachable = GraphDFS(graph, teamA, teamB, path, visited_nodes);
    }
    else if (search_mode == "BFS") {
        isreachable = GraphBFS(graph, teamA, teamB);
    }

	return isreachable;
}

/**
* In a depth first search for a target node the traversal
* through the graph goes first as far away from the base node
* as possible. If a sink is reached the traversal goes back  
* one level closer to the base and from there it goes again
* as far down as possible.
*
* If a node has more than one child, the DFS takes a random child first.
*
* Note: Does not necessarily find the shortest path because it goes
*       down the graph until it reaches the target.
*
* Note: For DFS you need a visited_nodes variable with larger scope
*       to safeguard against cycles if using a recursive approach.
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


/*
* A Breadth first search for a target node first checks all nodes that have distance 1 to the 
* base node. Then it goes trhough the nodes at level 1, at random order, collects
* the nodes that are distance one away from them (and thus distance 2 away from the base)
* and checks those nodes.
*
* Note: in a dfs search it is not easy to access to track the path that has
*       been traversed until the target node is found.
*
* Note: For BFS you also need a visited_nodes variable
*       to safeguard against cycles but since it is typically not implemented recursively
*       it can go inside the function.
*/
bool GraphBFS(
    const std::unordered_map<std::string, std::unordered_set<std::string>>& graph,
    const std::string& base_node,
    const std::string& target_node
    ) {

    bool target_visited = false;
    std::unordered_set<std::string> visited_nodes;

    std::queue<std::string> nodes_to_check;
    nodes_to_check.push(base_node);
    while (!nodes_to_check.empty()) {
        std::string curr_node = nodes_to_check.front();
        nodes_to_check.pop();
        visited_nodes.emplace(curr_node);
        // debug
        std::cout << "checking node " << curr_node << " " << std::endl;
        if (curr_node == target_node) {
            target_visited = true;
            break;
        }
        const std::unordered_set<std::string> children = graph.at(curr_node);
        for (auto it = children.begin(); it != children.end(); ++it) {
            const std::string& child = *it;
            // instead of putting a visited node to the queue and ignoring it
            // upon check later, simply do not even add visited nodes again
            if (visited_nodes.find(child) == visited_nodes.end()) {
                nodes_to_check.push(child);
            }            
        }
    }

    return target_visited;
}