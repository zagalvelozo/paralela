#include <iostream>
#include <string>

#include <mpi.h>

#include "map.h"
#include "debug.h"
#include "dijkstra.h"

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        std::cout << "try -v or -f STATION STATION" << std::endl;
        return -1;
    }
    else
    {
        std::string Argumento = argv[1];

        if (Argumento == "-v")
        {
            std::cout << "Leonardo Aillapan Cuellar"
                      << "\n"
                      << "Diego Pino Contreras"
                      << "\n"
                      << "Jesús Zagal Velozo"
                      << "\n";
        }
        else if (Argumento == "-f")
        {
            std::string Destino = argv[3];
            std::string Origen = argv[2];
            int mpiNodesCount, mpiNodeId;
            const int mpiRootId = 0;
            MPI_Init(&argc, &argv);
            MPI_Comm_size(MPI_COMM_WORLD, &mpiNodesCount);
            MPI_Comm_rank(MPI_COMM_WORLD, &mpiNodeId);
            //std::cout << "Hello from " << mpiNodeId << std::endl;

            if (mpiNodeId == mpiRootId)
            {
                Map m = Map::fromFile("metro");

                auto n = m.getNodesNames();
                int initialNodeName = getidstation(Origen);
                int goalNodeName = getidstation(Destino);
                //std::cout << "Origen: " << getnamestation(initialNodeName) <<std::endl;
                //std::cout << "Destino: " <<getnamestation(goalNodeName)<< std::endl;
                //std::cout << "Searching..." << std::endl;
                dijkstra(m, initialNodeName, goalNodeName, mpiNodesCount);
            }
            else
            {
                dijkstraWorker(mpiNodeId, mpiNodesCount);
            }

            MPI_Finalize();
            return 0;
        }
        else
        {
            std::cout << "try -v or -f STATION STATION" << std::endl;
            return 0;
        }
    }
}
