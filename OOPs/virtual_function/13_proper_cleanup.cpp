#include <iostream>
#include <string>

class Resource
{
public:
    // Constructor
    Resource(std::string name) : m_name(name)
    {
        std::cout << "Resource " << m_name << " acquired.\n";
    }

    // Virtual Destructor for proper cleanup
    virtual ~Resource()
    {
        std::cout << "Resource " << m_name << " released.\n";
    }

    virtual void use() const = 0; // Pure virtual function

protected:
    std::string m_name;
};

class FileResource : public Resource
{
public:
    FileResource(std::string name) : Resource(name)
    {
        // Simulating file opening
        std::cout << "Opening file: " << m_name << '\n';
    }

    ~FileResource() override
    {
        // Simulating file closing
        std::cout << "Closing file: " << m_name << '\n';
    }

    void use() const override
    {
        std::cout << "Reading file: " << m_name << '\n';
    }
};

class NetworkResource : public Resource
{
public:
    NetworkResource(std::string name) : Resource(name)
    {
        // Simulating network connection setup
        std::cout << "Setting up network connection for: " << m_name << '\n';
    }

    ~NetworkResource() override
    {
        // Simulating network connection cleanup
        std::cout << "Closing network connection for: " << m_name << '\n';
    }

    void use() const override
    {
        std::cout << "Sending data over network for: " << m_name << '\n';
    }
};

int main()
{
    // Creating resource objects dynamically
    Resource* res1 = new FileResource("file1.txt");
    Resource* res2 = new NetworkResource("server.com");

    // Using resources
    res1->use();
    res2->use();

    // Proper cleanup when objects are deleted
    delete res1; // Calls FileResource destructor and then Resource destructor
    delete res2; // Calls NetworkResource destructor and then Resource destructor

    return 0;
}
