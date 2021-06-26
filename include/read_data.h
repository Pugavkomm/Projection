#ifndef READ
#define READ

class Read_Data{
    public:
        Read_Data(const std::string& namefile);
        void open(const std::string& namefile);
        void close();
        void read_to_line(std::vector<Point>& line); 
    private:
        std::ifstream file;  
};

#endif