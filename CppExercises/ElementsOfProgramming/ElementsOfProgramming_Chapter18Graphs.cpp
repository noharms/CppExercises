
#include "pch.h"

#include "ElementsOfProgramming_Chapter18Graphs.h"

#include <iostream>
#include <queue>
#include <time.h>


typedef std::string std_str;
typedef std::unordered_map<std::string, std::unordered_set<std::string>> hashmap_team2beatenteams;

void ElementsOfProgrammingChapter18Graphs() {

	std::cout << "-- Entering ElementsOfProgrammingChapter18Graphs " << std::endl;

	//--------- Exercise: Win Reachability From Team A to Team B
	ElementsOfProgrammingChapter18Graphs_ExerciseWinReachability();

    //--------- Exercise 18.1: search a maze for a path from entrance to exit
    ElementsOfProgrammingChapter18Graphs_FindAPathFromEntranceToExit();


	return;
}


/**
 *----------------------------------------------------------------------------------------------
 *----------------------------------------------------------------------------------------------
 *----------------------------------------------------------------------------------------------
*/

/*
    Exercise description:

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

/** Exercise description:
*
*   Given a 2d array with only entries 0 or 1, imagine the elements represent
*   fields of a 2d maze, where 
*       1 = free field
*       0 = wall
*   Additionally one element is designated as the entrance and another one as
*   as the exit.
*
*   -> find a path from the entrance element to the exit element 
*       (no diagonal moving allowed)
*
*/
void ElementsOfProgrammingChapter18Graphs_FindAPathFromEntranceToExit() {
    
    // initialize randomization function rand()
    srand(time(NULL));

    // generate the maze
    const int kMazeSize = 5;
    const int kSlotFree = 1;
    const int kSlotFull = 0;
    std::array<std::array<bool, kMazeSize>, kMazeSize> maze;    
    for (int i = 0; i < kMazeSize; ++i) {
        for (int j = 0; j < kMazeSize; ++j) {
            int rand_number = rand() % 3;
            if (rand_number < 2) {
                maze[i][j] = kSlotFree;
            }
            else {
                maze[i][j] = kSlotFull;
            }
            
        }
    }
    // hard-set the bottom left to be the start
    // hard-set the top right to be the start
    maze[0][kMazeSize - 1] = kSlotFree;
    maze[kMazeSize - 1][0] = kSlotFree;
    const std::pair<int, int> startpos(0, kMazeSize - 1);
    const std::pair<int, int> endpos(kMazeSize - 1, 0);
    
    // print the maze
    std::cout << "The randomly generated maze looks like:" << std::endl;
    for (int i = 0; i < kMazeSize; ++i) {
        std::cout << "   |";
        for (int j = 0; j < kMazeSize; ++j) {
            if (i == startpos.first && j == startpos.second) {
                std::cout << "S";
                continue;
            } else if (i == endpos.first && j == endpos.second) {
                std::cout << "E";
                continue;
            }
            else {
                bool is_free = maze[i][j] == kSlotFree ? 1 : 0;
                if (!is_free) {
                    std::cout << "X";
                }
                else {
                    std::cout << "O";
                }
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    // build a graph that can be used
    std::unordered_map <std::string, std::unordered_set<std::string>> graph_free_neighbors;
    for (int i = 0; i < kMazeSize; ++i) {
        for (int j = 0; j < kMazeSize; ++j) {
            std::pair<int, int> position(i, j);
            const std::string key_mazenode = ToStringIndexPair(position);
            graph_free_neighbors[key_mazenode] = {};
            const int jm1 = j - 1;
            const int jp1 = j + 1;
            const int im1 = i - 1;
            const int ip1 = i + 1;
            std::pair<int, int> position_jm1(i, jm1);
            std::pair<int, int> position_jp1(i, jp1);
            std::pair<int, int> position_im1(im1, j);
            std::pair<int, int> position_ip1(ip1, j);
            const std::string key_node_jm1 = ToStringIndexPair(position_jm1);
            const std::string key_node_jp1 = ToStringIndexPair(position_jp1);
            const std::string key_node_im1 = ToStringIndexPair(position_im1);
            const std::string key_node_ip1 = ToStringIndexPair(position_ip1);
            if (jm1 >= 0 && maze[i][jm1] == kSlotFree) {                
                graph_free_neighbors[key_mazenode].emplace(key_node_jm1);
            }
            if (jp1 < kMazeSize && maze[i][jp1] == kSlotFree) {                                
                graph_free_neighbors[key_mazenode].emplace(key_node_jp1);
            }
            if (im1 >= 0 && maze[im1][j] == kSlotFree) {
                graph_free_neighbors[key_mazenode].emplace(key_node_im1);
            }
            if (ip1 < kMazeSize  && maze[ip1][j] == kSlotFree) {
                graph_free_neighbors[key_mazenode].emplace(key_node_ip1);
            }
        }
    }
    std::list<std::string> path;

    // use a depth first search
    const std::string start_node = ToStringIndexPair(startpos);
    const std::string target_node = ToStringIndexPair(endpos);
    std::cout << "-- starting dfs search from start to end of maze " << std::endl;
    std::unordered_set<std::string> visited_nodes = { start_node };
    bool isreachable = GraphDFS(graph_free_neighbors, start_node, target_node, path, visited_nodes);
    std::cout << "dfs search found that the end is" << (isreachable ? " " : "not ") << "connected to the start." << std::endl;
    std::string prev_node = start_node;
    if (isreachable) {
        std::cout << "The following path was found from " << start_node << " to " << target_node << " (note: there may be other paths): " << std::endl;
        for (auto it = path.begin(); it != path.end(); ++it) {
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
	std::list<std::string>& path,
    const std::string& search_mode) {
	
	// use a depth first search approach
    bool isreachable = false;
    
    if (search_mode == "DFS") {
        std::unordered_set<std::string> visited_nodes = { teamA };
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
* Note: the used generic type T needs to have the == operator defined
*/
bool GraphDFS(
    std::unordered_map<std::string, std::unordered_set<std::string>>& graph,
    std::string base,
    std::string target,
    std::list<std::string>& path,
    std::unordered_set<std::string>& visited_nodes) 
{
	
	// go through all nodes that are reachable from base
	auto reachable_nodes = graph[base];
	bool target_visited = false;
	for (auto it = reachable_nodes.begin(); it != reachable_nodes.end(); ++it) {
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



// create a string from the pair of indices 
// (a string representation is used as a key for for the hashmap to avoid custom hash-function)
std::string ToStringIndexPair(std::pair<int, int> indexpair) {
    return "(" + std::to_string(indexpair.first) + "," + std::to_string(indexpair.second) + ")";
}
