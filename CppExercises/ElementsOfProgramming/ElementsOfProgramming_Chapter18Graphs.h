#pragma once

#include <array>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <list>


const int kDim1 = 10;
const int kDim2 = 10;

struct IntPair {
  int x;
  int y;
};

// note: this datatype is only used in exercise 'cycle detection' at the moment
//       (in the other exercises the nodes were simply strings and the edges
//        were administrated in a hash_map from string to list of connected nodes)
typedef struct GRAPH_NODE_TYPE {
  GRAPH_NODE_TYPE(int i) : id(i) {}
  int id;
  std::vector<GRAPH_NODE_TYPE*> edges;
} GraphNodeType;

void ElementsOfProgrammingChapter18Graphs();

void ElementsOfProgrammingChapter18Graphs_ExerciseWinReachability();
void ElementsOfProgrammingChapter18Graphs_FindAPathFromEntranceToExit();
void ElementsOfProgrammingChapter18Graphs_FlipColorAdjacencyRegion();
void ElementsOfProgrammingChapter18Graphs_FlipColorTrappedWhiteFields();
void ElementsOfProgrammingChapter18Graphs_CycleDetection();

void FillatrandomWithBlackAndWhite2dMatrix(std::array< std::array<int, kDim2>, kDim1>* mat_ptr,
  const int max_rand_number,
  const int white_threshold);

bool FindWinningPath(
    std::unordered_map<std::string, std::unordered_set<std::string>>& graph,
    std::string teamA,
    std::string teamB,
    std::list<std::string>& path,
    const std::string& search_mode);

bool GraphDFS(
    std::unordered_map<std::string, std::unordered_set<std::string>>& graph,
    std::string base,
    std::string target,
    std::list<std::string>& path,
    std::unordered_set<std::string>& visited_nodes);

bool GraphBFS(
    const std::unordered_map<std::string, std::unordered_set<std::string>>& graph,
    const std::string& base_node,
    const std::string& target_node
);

void FlipColorAdjacencyRegion(std::array<std::array<int, kDim2>, kDim1>* mat_ptr,
  const IntPair pt,
  const int reference_value);

void FlipColorBorderedRegions(std::array<std::array<int, kDim2>, kDim1>* matrix_ptr);
void TraverseAndMarkAdjacencyRegion(std::array<std::array<int, kDim2>, kDim1>* matrix_ptr,
  const IntPair point);

void PrintColorMatrix(std::array<std::array<int, kDim2>, kDim1> arr);

std::string ToStringIndexPair(std::pair<int, int> indexpair);

bool GraphDFSForCycle_Wrapper(std::vector<GraphNodeType>* graph_ptr);
bool GraphDFSForCycle(
  GraphNodeType* curr_node_ptr,
  std::unordered_set<int>* ancestors_ptr,
  std::unordered_set<int>* visited_ptr);