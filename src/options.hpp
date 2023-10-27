/*
 * This file is for parser options.
 */

#ifndef OPTIONS_HPP
#define OPTIONS_HPP

#include <boost/noncopyable.hpp>
#include <boost/program_options.hpp>
#include <string>
#include <ostream>

class program_options : boost::noncopyable
{
public:
        program_options() {}

        /** parse and store command line options */
        void parse(int args, char** argv);
        /** print options value */
        void print(std::ostream& ostr, std::string const& prefix ="");

        /** retrieve option value as specified type */

        /** retrieve option value as sepcified type */
        template <typename T>
        T get(std::string const& name) const
        {
                if (!vm_.count(name)){
                        throw std::logic_error("missing option value: "+name);
                }
                return vm_[name].as<T>();
        }

        double get(std::string const& name) const
        {
                return get<double>(name);
        }

        std::string get_path(std::string const& name) const
        {
                return get<std::string>(name);
        }

        /** check whether option value exists */
        bool has(std::string const& name) const
        {
                return vm_.count(name) > 0;
        }


private:
        /** store parsed program options */
        boost::program_options::variables_map vm_;
};

#endif /* ! OPTIONS_HPP */
