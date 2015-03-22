
#include <vector>
#include <iostream>


std::vector<unsigned int> joVect(unsigned int n, unsigned int m){

	std::vector<unsigned int> results;
	std::vector<unsigned int> prisoners;

	//populate vector
	for (int i = 0; i <= n; i++){
		prisoners.push_back(i);
	}
	
	
	while(prisoners.size()!=1){
		std::vector<unsigned int> pendingExecution;
		for (int j = 0; j < prisoners.size(); j++){
//			std::cout << "loop iteration: "<< j << "\n";
			if(j % m == 1){
//				std::cout << " -> (prisoner:" << prisoners.at(j) << ") " //<< j << " % " << m << " = 1 -> nth one, delete and add to final vector\n";
				results.push_back(prisoners.at(j));
				//prisoners.erase(prisoners.begin()+j);
				//prisoners.erase(prisoners.begin()+j);
				pendingExecution.push_back(prisoners.at(j));
			}
			else {
//				std::cout << " -> (" << prisoners.at(j) << ") " << j << " % " << m << " not the nth one  \n";
			}
		}
		
		// loop through all pending execution
		for(int i = 0; i < pendingExecution.size(); i++){
			// loop through all prisoners for each pending
			for(int k = 0; k < prisoners.size(); k++){
				// if pending matches execution
				if (prisoners.at(k)==pendingExecution.at(i)){
					prisoners.erase(prisoners.begin()+k);
				}
			}
		}

//		std::cout << " p.size() " << prisoners.size() << "\n";
	}

	return results;
}
