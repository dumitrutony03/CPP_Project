//
// Created by tonyc on 5/9/2023.
//

#include "TestList.h"

#include "TestList.h"
#include "List.h"
#include <cassert>
#include <vector>

void TestList::test_push_back()
{
    List<int> newList;
    newList.push_back(1);
    newList.push_back(2);
    newList.push_back(3);
    newList.push_back(4);
    assert(newList.size() == 4);
    cout << "Test push_back() trecut!" << endl;
}

void TestList::test_get_at() {
    List<int> newList;
    newList.push_back(1);
    newList.push_back(2);
    newList.push_back(3);
    newList.push_back(4);
    assert (newList.get_at(0) == 1);
    assert (newList.get_at(1) == 2);
    assert (newList.get_at(2) == 3);
    assert (newList.get_at(3) == 4);

    cout << "Test get_at() trecut!" <<  endl;
}

void TestList::test_update() {
    List<int> newList;
    newList.push_back(1);
    newList.push_back(2);
    newList.push_back(3);
    newList.push_back(4);
    newList.update(2, 17);
    assert (newList.get_at(0) == 1);
    assert (newList.get_at(1) == 2);
    assert (newList.get_at(2) == 17);
    assert (newList.get_at(3) == 4);
    try{
        newList.update(5, 100);
        assert(false);
    }
    catch (const std::invalid_argument& e){
        //cout << "Exceptie: " << e.what() << endl;
        assert(true);
    }
    catch(...){
        cout << "Exceptie neintalnita..." << endl;
    }
    cout << "Test update() trecut!" << endl;
}

void TestList::test_search() {
    List<int> newList;
    newList.push_back(3);
    newList.push_back(1);
    newList.push_back(2);
    newList.push_back(3);
    assert(newList.search(1) == 1);
    assert(newList.search(3) == 0);
    assert(newList.search(100) == -1);
    cout << "Test search() trecut!" << endl;
}

void TestList::test_set_at() {
    List<int> newList;
    newList.push_back(1);
    newList.push_back(2);
    newList.push_back(3);
    newList.push_back(4); // 1 2 3 4
    newList.set_at(2, 5); // 1 2 5 3 4

    assert(newList.search(5) == 2);
    newList.set_at(0, 7); // 7 1 2 5 3 4
    assert(newList.search(7) == 0);

    try{
        newList.set_at(7, 100);
        assert(false);
    }
    catch (std::invalid_argument &ex){
        assert(true);
    }
    catch(...)
    {
        assert(true);
    }
    cout << "Test set_at() trecut!" << endl;
}

void TestList::test_delete_at() {
    List<int> newList;
    newList.push_back(3);
    newList.push_back(1);
    newList.push_back(2);
    newList.push_back(3);

    newList.delete_at(2);
    assert(newList.size() == 3);
    assert(newList.search(2) == -1);
    assert(newList.get_at(2) == 3);

    try{
        newList.delete_at(5);
        assert(false);
    }
    catch(std::exception &ex){
        assert(true);
    }
}

void TestList::test_push_front() {
    List<int> newList;
    assert(newList.is_empty() == true);
    newList.push_back(1);
    newList.push_back(2);
    newList.push_back(3);
    assert(newList.is_empty() == false);
    assert(newList.size() == 3);

    newList.push_front(4);
    assert(newList.size() == 4);
    assert(newList.get_at(0) == 4);
    assert(newList.get_at(1) == 1);
    assert(newList.get_at(2) == 2);
    assert(newList.get_at(3) == 3);
    cout << "Test push_front() trecut!" << endl;
}

