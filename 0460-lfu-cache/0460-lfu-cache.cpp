class LFUCache {
private:
    int capacity, minFreq;
    unordered_map<int, pair<int, int>> keyValFreq;
    unordered_map<int, list<int>> freqKeys;
    unordered_map<int, list<int>::iterator> keyIter;

    void updateFreq(int key) {
        int freq = keyValFreq[key].second;
        freqKeys[freq].erase(keyIter[key]);

        if (freqKeys[freq].empty()) {
            freqKeys.erase(freq);
            if (minFreq == freq) minFreq++;
        }

        keyValFreq[key].second++;
        freqKeys[freq + 1].push_front(key);
        keyIter[key] = freqKeys[freq + 1].begin();
    }

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }
    
    int get(int key) {
        if (!keyValFreq.count(key)) return -1;

        updateFreq(key);
        return keyValFreq[key].first;
    }
    
    void put(int key, int value) {
        if (capacity == 0) return;

        if (keyValFreq.count(key)) {
            keyValFreq[key].first = value;
            updateFreq(key);
            return;
        }

        if (keyValFreq.size() == capacity) {
            int evictKey = freqKeys[minFreq].back();
            freqKeys[minFreq].pop_back();

            if (freqKeys[minFreq].empty()) freqKeys.erase(minFreq);

            keyValFreq.erase(evictKey);
            keyIter.erase(evictKey);
        }

        keyValFreq[key] = {value, 1};
        freqKeys[1].push_front(key);
        keyIter[key] = freqKeys[1].begin();
        minFreq = 1;
    }
};