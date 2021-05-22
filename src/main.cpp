/**
* @file main.cpp
* @author vss2sn
* @brief The main function that sets up the problem and runs the solution algorithms
*/

#include "main.hpp"

int main(int argc, char * argv[]){

  Problem p(10,4,8,5,10, "uniform");

  std::cout << "Greedy: " << '\n';
  GreedySolution vrp_greedy(p);
  vrp_greedy.Solve();
  std::cout << '\n';

  std::cout << "Local Search (Within each vehicle separately): " << '\n';
  LocalSearchIntraSolution vrp_lsi(p);
  vrp_lsi.Solve();
  std::cout << '\n';

  std::cout << "Local Search (Within all vehicles): " << '\n';
  LocalSearchInterIntraSolution vrp_lsii(p);
  vrp_lsii.Solve();
  std::cout << '\n';

  std::cout << "Tabu Search: " << '\n';
  TabuSearchSolution vrp_ts(p, 10);
  vrp_ts.Solve();
  std::cout << '\n';

  std::cout << "Genetic Algorithm: " << '\n';
  GASolution vrp_ga(p, 5, 100);
  vrp_ga.Solve();
  std::cout << '\n';

  std::cout << "Simulated Annealing: " << '\n';
  SimulatedAnnealingSolution vrp_sa(p, 5000000, 5000, 0.9999);
  vrp_sa.Solve();
  std::cout << '\n';

  // NOTE: The following are examples of how to create solutions by using the
  // algorithms coded in this repository sequentially, effectively allowing
  // the creation of hybrid algorithms/solutions.

  // Example 1
  // std::cout << "Hybrid Example 1: " << '\n';
  // GreedySolution vrp_greedy_for_hybrid(p);
  // vrp_greedy_for_hybrid.Solve();
  // Solution s = vrp_greedy_for_hybrid; // Strip out solution from vrp_greedy_for_hybrid.
  // LocalSearchInterIntraSolution vrp_lsii_for_hybrid(s);
  // vrp_lsii_for_hybrid.Solve();
  // std::cout << '\n';

  // Example 2
  // std::cout << "Hybrid Example 2: " << '\n';
  // GASolution vrp_ga_for_hybrid(p, 25, 500000);;
  // vrp_ga_for_hybrid.Solve();
  // Solution s = vrp_ga_for_hybrid; // Strip out solution from vrp_greedy_for_hybrid.
  // LocalSearchInterIntraSolution vrp_lsii_for_hybrid(s);
  // vrp_lsii_for_hybrid.Solve();
  // std::cout << '\n';

  return 0;
}
