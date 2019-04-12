
#include "pch.h"

#include "ElementsOfProgramming_Chapter18Graphs.h"

#include <iostream>
#include <queue>
#include <time.h>


const int kWHITE = 1;
const int kBLACK = 0;
const int kFLIPPED = 2;

typedef std::string std_str;
typedef std::unordered_map<std::string, std::unordered_set<std::string>> hashmap_team2beatenteams;

void ElementsOfProgrammingChapter18Graphs() {

	std::cout << "-- Entering ElementsOfProgrammingChapter18Graphs " << std::endl;

  //--------- Exercise: Win Reachability From Team A to Team B
  std::cout << "------------------------------" << std::endl;
  std::cout << "-- Exercise: Win Reachability: " << std::endl;
  std::cout << "------------------------------" << std::endl;
	ElementsOfProgrammingChapter18Graphs_ExerciseWinReachability();

  //--------- Exercise 18.1: search a maze for a path from entrance to exit
  std::cout << "------------------------------" << std::endl;
  std::cout << "-- Exercise: 18.1 " << std::endl;
  std::cout << "------------------------------" << std::endl;
  ElementsOfProgrammingChapter18Graphs_FindAPathFromEntranceToExit();

  //--------- Exercise 18.2: flip color of adjacency region around given point
  std::cout << "------------------------------" << std::endl;
  std::cout << "-- Exercise: 18.2 " << std::endl;
  std::cout << "------------------------------" << std::endl;
  ElementsOfProgrammingChapter18Graphs_FlipColorAdjacencyRegion();
  
  //--------- Exercise 18.3: flip color of trapped white fields
  std::cout << "------------------------------" << std::endl;
  std::cout << "-- Exercise: 18.3 " << std::endl;
  std::cout << "------------------------------" << std::endl;
  ElementsOfProgrammingChapter18Graphs_FlipColorTrappedWhiteFields();

  //--------- Exercise 18.4: detection of cycle
  std::cout << "------------------------------" << std::endl;
  std::cout << "-- Exercise: 18.4 " << std::endl;
  std::cout << "------------------------------" << std::endl;
  ElementsOfProgrammingChapter18Graphs_CycleDetection();

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
    srand((unsigned int)time(NULL));

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

/** Exercise description

    given a 2d matrix of black and white entries,
    and one point inside the matrix,
    flip all fields that are in the same-color-adjacency region of the given point:
    the region is defined by those points having the same color as the given point
    and being reachable by up, down, rght, left movements
    from the given point on a path over fields of the same color
 */
void ElementsOfProgrammingChapter18Graphs_FlipColorAdjacencyRegion() {
  
  // create 2d random filled matrix
  std::array<std::array<int, kDim2>, kDim1> matrix;
  FillatrandomWithBlackAndWhite2dMatrix(&matrix, 3, 2);

  // output the randomly created matrix
  PrintColorMatrix(matrix);

  // choose a point at random
  IntPair anchor_pt;
  anchor_pt.x = rand() % kDim1;
  anchor_pt.y = rand() % kDim2;
  std::cout << "Anchor point: x=" << anchor_pt.x << ", y=" << anchor_pt.y << std::endl << std::endl;
    
  // Flip the color in the adjacency region
  const int val_at_anchor_pt = matrix.at(anchor_pt.x).at(anchor_pt.y);
  FlipColorAdjacencyRegion(&matrix, anchor_pt, val_at_anchor_pt);
    
  // output the matrix after flipping colors
  PrintColorMatrix(matrix); 

  return;
}


/** Exercise description

    given a 2d matrix of black and whit entires,
    we consider those white fields trapped that do not have
    a connection to a whit field at the border of the matrix
    (a connection means a path over other white fields with only
    top, down, left, rght movement allowed)

    the task is to flip all white fields that are trapped to black.
*/
void ElementsOfProgrammingChapter18Graphs_FlipColorTrappedWhiteFields() {

  // create 2d random filled matrix
  std::array<std::array<int, kDim2>, kDim1> matrix;
  FillatrandomWithBlackAndWhite2dMatrix(&matrix, 4, 2);

  // output the randomly created matrix
  PrintColorMatrix(matrix);
  
  // Flip the color of all adjacency regions that do not reach the boundary
  FlipColorBorderedRegions(&matrix);

  // output the matrix after flipping colors
  PrintColorMatrix(matrix);

  return;
}

/** Exercise description

    Given a directed graph (that is not necessarily strongly connected)
    find out whether the graph contains a cycle or not.

*/
void ElementsOfProgrammingChapter18Graphs_CycleDetection() {

  // build some graph with random connections
  const int kNumberNodes = 5;

  // let's represent the graph here as a vector of nodes
  std::vector<GraphNodeType> graph;
  for (int i = 0; i < kNumberNodes; ++i) {
    graph.emplace_back(GraphNodeType(i));
  }
  // add edges at random between the nodes
  for (int i = 0; i < kNumberNodes; ++i) {
    for (int j = 0; j < kNumberNodes; ++j) {
      if (j == i) {
        continue; // edges to oneself would make no sense..
      }
      // 50:50 chance that node i has an edge to node j
      if (rand() % 2) {
        GraphNodeType* connected_node_ptr = &(graph[j]);
        graph[i].edges.emplace_back(connected_node_ptr);
      }
    }
  }

  // show the connections
  std::cout << "The graph contains the following edges:" << std::endl;
  for (int i = 0; i < kNumberNodes; ++i) {
    std::cout << "Node with id=" << graph[i].id << " has edges to: ";
    for (size_t k = 0; k < graph[i].edges.size(); ++k) {
      GraphNodeType* connected_node_ptr = graph[i].edges.at(k);
      std::cout << connected_node_ptr->id << ", ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;

  // check if there is a cycle
  bool contains_cycle = GraphDFSForCycle_Wrapper(&graph);

  // print result
  if (contains_cycle) {
    std::cout << "Result: a cycle was detected in the graph." << std::endl;
  }
  else {
    std::cout << "Result: NO cycle detected in the graph." << std::endl;
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

void FlipColorAdjacencyRegion(std::array<std::array<int, kDim2>, kDim1>* mat_ptr,
  const IntPair pt,
  const int reference_value) {

  std::array<std::array<int, kDim2>, kDim1>& A = *mat_ptr;

  A.at(pt.x).at(pt.y) = kFLIPPED;

  const IntPair kDirs[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

  // check all four neighbors, if they also have the same reference value
  for (auto & dir : kDirs) {
    int i = pt.x + dir.x;
    int j = pt.y + dir.y;
    if (i >= 0 && i < kDim1 && j >= 0 && j < kDim2) {
      int value_at_neighbor = A[i][j];
      if (value_at_neighbor == reference_value) {
        FlipColorAdjacencyRegion(mat_ptr, { i, j }, reference_value);
      }
    }
  }


  return;
}

void FlipColorBorderedRegions(std::array<std::array<int, kDim2>, kDim1>* matrix_ptr) {

  std::array<std::array<int, kDim2>, kDim1>& mat = *matrix_ptr;

  // find all adjacency regions that CAN reach the boundary
  // go through top and bottom row
  for (size_t j = 0; j < mat.at(0).size(); ++j) {
    int val = mat[0][j];
    if (val == kWHITE) {
      TraverseAndMarkAdjacencyRegion(matrix_ptr, IntPair{ 0, (int)j });
    }
    val = mat[(mat.size() - 1)][j];
    if (val == kWHITE) {
      TraverseAndMarkAdjacencyRegion(matrix_ptr, IntPair{ (int)mat.size() - 1, (int)j });
    }
  }
  // go through leftmost and rightmost collumn    
  for (size_t i = 0; i < mat.size(); ++i) {
    int val = mat[i][0];
    if (val == kWHITE) {
      TraverseAndMarkAdjacencyRegion(matrix_ptr, IntPair{ (int)i, 0 });
    }
    val = mat[i][mat.at(i).size() - 1];
    if (val == kWHITE) {
      TraverseAndMarkAdjacencyRegion(matrix_ptr, IntPair{ (int)i, (int)mat.at(i).size() - 1 });
    }
  }

  // make all the inner fields that are still white black
  for (size_t i = 1; i < mat.size() - 1; ++i) {
    for (size_t j = 1; j < mat.at(i).size() - 1; ++j) {
      if (mat[i][j] == kWHITE) {
        mat[i][j] = kBLACK;
      }
    }
  }


  return;
}

void TraverseAndMarkAdjacencyRegion(std::array<std::array<int, kDim2>, kDim1>* matrix_ptr,
  const IntPair point)
{
  std::array<std::array<int, kDim2>, kDim1>& matrix = *matrix_ptr;

  matrix[point.x][point.y] = kFLIPPED;

  // check for neighbors that might be flipped as well
  const IntPair kDirs[4] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

  for (auto dir : kDirs) {
    int i = point.x + dir.x;
    int j = point.y + dir.y;
    if (i >= 0 && i < (int)matrix.size() && j >= 0 && j < (int)matrix.at(i).size()) {
      if (matrix.at(i).at(j) == kWHITE) {
        TraverseAndMarkAdjacencyRegion(matrix_ptr, IntPair{ i, j });
      }
    }
  }

  return;
}


void PrintColorMatrix(std::array<std::array<int, kDim2>, kDim1> arr) {

  std::cout << "The matrix is: " << std::endl;
  for (size_t i = 0; i < arr.size(); ++i) {
    std::cout << "Line " << i << "| ";
    for (size_t j = 0; j < arr.at(0).size(); ++j) {
      int val_at_ij = arr.at(i).at(j);
      switch (val_at_ij) {
      case kWHITE:
        std::cout << "O";
        break;
      case kBLACK:
        std::cout << "X";
        break;
      case kFLIPPED:
        std::cout << "F";
        break;
      default:
        std::cout << "E";  // E for Error , should not be reached
        break;
      }
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;


  return;
}

/* Fill at random a given 2d matrix 
 
   play with max_rand_number and white_threshold to shift ratio of white to black fields
*/
void FillatrandomWithBlackAndWhite2dMatrix(std::array< std::array<int, kDim2>, kDim1>* mat_ptr, 
  const int max_rand_number, 
  const int white_threshold) {
  
  srand((unsigned int) time(NULL));

  std::array< std::array<int, kDim2>, kDim1>& matrix = *mat_ptr;

  for (int i = 0; i < kDim1; ++i) {
    for (int j = 0; j < kDim2; ++j) {
      int rand_number = rand() % max_rand_number;
      if (rand_number < white_threshold) {
        matrix[i][j] = kWHITE;
      }
      else {
        matrix[i][j] = kBLACK;
      }
    }
  }

  return;
}


/** Wrapper for the DFS that uses a list of ancestors and a list of visited nodes
    with higher scope.

    --> these lists are defined in the wrapper and then passed to the
        recursive DFS function

*/
bool GraphDFSForCycle_Wrapper(std::vector<GraphNodeType>* graph_ptr) {

  bool graph_contains_cycle = false;

  std::vector<GraphNodeType>& graph = *graph_ptr;

  // create empty sets for tracking visited nodes and ancestor nodes
  std::unordered_set<int> ancestors;
  std::unordered_set<int> visited;

  for (size_t i = 0; i < graph.size(); ++i) {
    graph_contains_cycle = GraphDFSForCycle(&(graph[i]), &ancestors, &visited);
    if (graph_contains_cycle) {
      break;
    }
  }  

  return graph_contains_cycle;
}

/**
    Recursive DFS function to detect a cycle.

    Relies on outer scope lists for ancestors and visited nodes. 

*/
bool GraphDFSForCycle(
  GraphNodeType* curr_node_ptr,
  std::unordered_set<int>* ancestors_ptr,
  std::unordered_set<int>* visited_ptr) {
    
  std::unordered_set<int>& ancestors = *ancestors_ptr;
  std::unordered_set<int>& visited = *visited_ptr;
  
  if (ancestors.find(curr_node_ptr->id) != ancestors.end()) { // this node is its own ancestor
    // print for debug
    std::cout << "ALERT: cycle detected!" << std::endl;
    std::cout << "-> We reached node with id=" << curr_node_ptr->id;
    std::cout << " in a search branch that contains the same node as an ancestor." << std::endl;
    std::cout << "(current list of ancestors: ";
    for (auto& it : ancestors) {
      std::cout << it << ", ";
    }
    std::cout << ")" << std::endl;
    return true;
  }
  else if (visited.find(curr_node_ptr->id) != visited.end()) {   // node already visited
    return false;
  }
  else {
    // if the current node was neither visited before nor its own ancestor
    // we can start to look into its descendents
    visited.emplace(curr_node_ptr->id);
    ancestors.emplace(curr_node_ptr->id);
    std::vector<GraphNodeType*>& connected_nodes = curr_node_ptr->edges;
    for (auto& connected_node_ptr : connected_nodes) {      
      if (GraphDFSForCycle(connected_node_ptr, ancestors_ptr, visited_ptr)) {
        return true; // if we find a cycle at some point, we can stop the search and return true
      }
    }
    // if we are done processing the descendents of the current node, it will no longer be an
    // ancestor for the next nodes that we visit
    ancestors.erase(curr_node_ptr->id);
    return false;
  }

}