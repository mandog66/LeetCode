class RandomizedSet
{
public:
    RandomizedSet()
    {
    }

    bool insert(int val)
    {
        this->ret = randomizedSet.insert(val);
        return this->ret.second;
    }

    bool remove(int val)
    {
        return this->randomizedSet.erase(val);
    }

    int getRandom()
    {
        set<int>::iterator it = this->randomizedSet.begin();
        int r = rand() % (this->randomizedSet.size()); // get random number [0, randomizedSet.size())
        advance(it, r);                                // get randomizedSet element of index
        return *(it);
    }

    pair<set<int>::iterator, bool> ret; // ret = {val, bool}. inser(1) and 1 not in the set, ret = {1, true}
    set<int> randomizedSet;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */