#include <vector>
#include <iostream>
#include <fstream>
#include "options.hpp"
#include "microscopic_fluation_correlation.hpp"


#define PROGRAM_NAME "Microscopic fluctuation correlations"

int main(int argc, char** argv)
{
        /* From options.hpp, as parser */
        program_options options;
        options.parse(argc, argv);

        std::cout<<"File path is "<< options.get_path("filepath")<<std::endl;
        std::string filepath = options.get_path("filepath");

        std::cout<<"Time step(dt) is" << options.get("timestep")<<std::endl;
        double dt = options.get("timestep");
        
        /* Open file */
        std::ifstream inputfile;
        inputfile.open(filepath);
        std::cout<<"Reading file"<<std::endl;
        if(!inputfile)
        {
                std::cout<<"unable to read file";
                exit(1);
        }

        double x;
        std::vector<double> traj;
        while(inputfile>>x)
        {
                traj.push_back(x);
        }

        Fluctuation_Correlation FC(traj);
        // Population calculation
        double* population = FC.population_fluctuation();
        // Correlation calculation
        double* correlation = FC.correlation(population);

        //Record data
        std::ofstream corhh;
        corhh.open("./corhh.txt");
        int N=1000000;
        if(N>traj.size())
                N = traj.size();
        for(size_t i=0; i<N; i++)
        {
                corhh<<i*dt<<" "<<correlation[i]<<std::endl;
        }
        std::cout<<"Record data done"<<std::endl;

        // Release memory
        delete[] correlation;
        delete[] population;
        return 0;
}

void program_options::parse(int argc, char** argv)
{
        namespace po = boost::program_options;
        po::options_description desc("Program options");
        desc.add_options()
                ("filepath", po::value<std::string>()->required(), "trajectory file path")

                ("timestep", po::value<double>()->required(), "timestep dt")

                ("output",   po::value<std::string>()->default_value("flux_correlation.txt"), "output path")

                ("help", "display the options and exit")
                ;

        try {
                po::command_line_parser parser(argc, argv);
                po::parsed_options parsed(parser.options(desc).run());
                po::store(parsed, vm_);

                if (vm_.count("help")) {
                        std::cout << "Usage: " PROGRAM_NAME " [OPTION]...\n\n" << desc <<std::endl;
                        exit(EXIT_SUCCESS);
                }

                po::notify(vm_);
        }
        catch (std::exception const& e) {
                std::cerr <<PROGRAM_NAME ":"<<e.what() <<"\n\n";
                std::cerr << "Try '" PROGRAM_NAME "--help' for more information." << std::endl;
                exit(EXIT_FAILURE);
        }
}
