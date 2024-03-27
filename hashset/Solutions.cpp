class MyHashSet
{
public:
    int maxKey = 1000000;
    vector<bool> hash;

    MyHashSet()
    {
        hash.resize(maxKey + 1, false);
    }

    void add(int key)
    {
        hash[key] = true;
    }

    void remove(int key)
    {
        hash[key] = false;
    }

    bool contains(int key)
    {
        return hash[key];
    }
};