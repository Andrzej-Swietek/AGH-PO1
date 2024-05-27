#ifndef MYTHREADSAFESTUFF_H
#define MYTHREADSAFESTUFF_H
#include <iostream>
#include <queue>
#include <mutex>
#include <unordered_map>



template<typename T>
class ThreadSafeQueue {
private:
    std::queue<T> data;
    mutable std::mutex mtx;

public:
    void push(const T& value) {
        std::lock_guard<std::mutex> lock(mtx);
        data.push(value);
    }

    T pop() {
        std::lock_guard<std::mutex> lock(mtx);
        if (data.empty()) {
            throw std::runtime_error("Queue is empty");
        }
        T value = data.front();
        data.pop();
        return value;
    }

    bool isEmpty() const {
        std::lock_guard<std::mutex> lock(mtx);
        return data.empty();
    }
};

template<typename Key, typename Value>
class ThreadSafeHashMap {
private:
    std::unordered_map<Key, Value> data;
    mutable std::mutex mtx;

public:
    void insert(const Key& key, const Value& value) {
        std::lock_guard<std::mutex> lock(mtx);
        data[key] = value;
    }

    bool find(const Key& key, Value& value) const {
        std::lock_guard<std::mutex> lock(mtx);
        auto it = data.find(key);
        if (it != data.end()) {
            value = it->second;
            return true;
        }
        return false;
    }

    bool isEmpty() const {
        std::lock_guard<std::mutex> lock(mtx);
        return data.empty();
    }
};



#endif // MYTHREADSAFESTUFF_H