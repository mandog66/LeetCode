class Bucket
{
private:
    vector<pair<int, int>> bucket;

public:
    int get(int key)
    {
        for (auto it : bucket)
        {
            if (it.first == key)
                return it.second;
        }
        return -1;
    }

    void update(int key, int val)
    {
        bool found = false;
        for (int i = 0; i < bucket.size(); i++)
        {
            if (bucket[i].first == key)
            {
                bucket[i].second = val;
                found = true;
            }
        }
        if (!found)
            bucket.push_back(make_pair(key, val));
    }

    void remove(int key)
    {
        for (int i = 0; i < bucket.size(); i++)
        {
            if (bucket[i].first == key)
            {
                bucket.erase(bucket.begin() + i);
                break;
            }
        }
    }
};

class MyHashMap
{
public:
    vector<Bucket> hash_table;
    int key_space;
    MyHashMap()
    {
        key_space = 2069;
        for (int i = 0; i < key_space; i++)
            hash_table.push_back(Bucket());
    }

    void put(int key, int value)
    {
        int hash_key = key % key_space;
        hash_table[hash_key].update(key, value);
    }

    int get(int key)
    {
        int hash_key = key % key_space;
        return hash_table[hash_key].get(key);
    }

    void remove(int key)
    {
        int hash_key = key % key_space;
        hash_table[hash_key].remove(key);
    }
};