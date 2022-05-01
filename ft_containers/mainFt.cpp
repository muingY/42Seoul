/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainFT.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 11:46:40 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/10/06 14:49:20 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/vector/vector.hpp"
#include "ft/map/map.hpp"
#include "ft/stack/stack.hpp"
#include <iostream>
#include <string>
#include <time.h>

/*
* Tools
*/
namespace timeTool
{
    static double stime;
    static double etime;
    void setStartTime() { stime = clock(); }
    void setEndTime() { etime = clock(); }
    double getDeltaTime() { return etime - stime; }
}

/*
* Test containers
*/
void test_vector()
{
    ft::vector<int> intv1;
    ft::vector<int> intv2((size_t)10, 42);

    intv1.push_back(10);
    intv1.push_back(20);
    intv1.push_back(30);
    intv1.push_back(40);

    std::cout << "intv1 = ";
    for (int i = 0; i < intv1.size(); i++)
    {
        std::cout << intv1[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "intv2 iterator = ";
    for (ft::vector<int>::iterator iter = intv2.begin(); iter != intv2.end(); iter++)
    {
        std::cout << *iter << " ";
    }
    std::cout << std::endl;
    std::cout << "intv1 reverse iterator = ";
    for (ft::vector<int>::reverse_iterator riter = intv1.rbegin(); riter != intv1.rend(); riter++)
    {
        std::cout << *riter << " ";
    }
    std::cout << std::endl;

    std::cout << "intv1 size = " << intv1.size() << std::endl;
    std::cout << "intv2 size = " << intv2.size() << std::endl;
    std::cout << "intv1 capacity = " << intv1.capacity() << std::endl;
    std::cout << "intv2 capacity = " << intv2.capacity() << std::endl;
    std::cout << "intv1.push_back(50)" << std::endl;
    intv1.push_back(50);
    std::cout << "intv1 size = " << intv1.size() << std::endl;
    std::cout << "intv1 capacity = " << intv2.capacity() << std::endl;

    std::cout << "(intv1 == intv2) = ";
    std::cout << static_cast<int>(intv1 == intv2) << std::endl;
    std::cout << "(intv1 == intv1) = ";
    std::cout << static_cast<int>(intv1 == intv1) << std::endl;
    std::cout << "(intv1 != intv2) = ";
    std::cout << static_cast<int>(intv1 != intv2) << std::endl;
    std::cout << "(intv1 >= intv2) = ";
    std::cout << static_cast<int>(intv1 >= intv2) << std::endl;
    std::cout << "(intv1 <= intv2) = ";
    std::cout << static_cast<int>(intv1 <= intv2) << std::endl;
    std::cout << "(intv1 > intv2) = ";
    std::cout << static_cast<int>(intv1 > intv2) << std::endl;
    std::cout << "(intv1 < intv2) = ";
    std::cout << static_cast<int>(intv1 < intv2) << std::endl;

    std::cout << "intv1.swap(intv2)" << std::endl;
    intv1.swap(intv2);
    std::cout << "intv1 = ";
    for (int i = 0; i < intv1.size(); i++)
    {
        std::cout << intv1[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "intv2 = ";
    for (int i = 0; i < intv2.size(); i++)
    {
        std::cout << intv2[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "intv1.swap(intv2)" << std::endl;
    intv1.swap(intv2);
    std::cout << "intv1 = ";
    for (int i = 0; i < intv1.size(); i++)
    {
        std::cout << intv1.at(i) << " ";
    }
    std::cout << std::endl;
    std::cout << "intv2 = ";
    for (int i = 0; i < intv2.size(); i++)
    {
        std::cout << intv2.at(i) << " ";
    }
    std::cout << std::endl;

    std::cout << "intv2.assign(3, 42)" << std::endl;
    intv2.assign((size_t)3, 42);
    std::cout << "intv2 size = " << intv2.size() << std::endl;
    std::cout << "intv2 = ";
    for (int i = 0; i < intv2.size(); i++)
    {
        std::cout << intv2.at(i) << " ";
    }
    std::cout << std::endl;
    std::cout << "intv2.assign(intv1.begin(), intv1.begin() + 5)" << std::endl;
    intv2.assign(intv1.begin(), intv1.begin() + 5);
    std::cout << "intv2 size = " << intv2.size() << std::endl;
    std::cout << "intv2 = ";
    for (int i = 0; i < intv2.size(); i++)
    {
        std::cout << intv2.at(i) << " ";
    }
    std::cout << std::endl;

    std::cout << "intv1.front() = " << intv1.front() << std::endl;
    std::cout << "intv1.back() = " << intv1.back() << std::endl;

    std::cout << "intv2 size = " << intv2.size() << std::endl;
    std::cout << "intv2.clear()" << std::endl;
    intv2.clear();
    std::cout << "intv2 size = " << intv2.size() << std::endl;

    std::cout << "*(intv1.data()) = " << *(intv1.data()) << std::endl;

    std::cout << "intv1.empty() = " << static_cast<int>(intv1.empty()) << std::endl;
    std::cout << "intv2.empty() = " << static_cast<int>(intv2.empty()) << std::endl;
    
    std::cout << "intv2 <- 3, 2, 1" << std::endl;
    intv2.push_back(3);
    intv2.push_back(2);
    intv2.push_back(1);
    std::cout << "intv2 size = " << intv2.size() << std::endl;
    std::cout << "intv2.erase(intv2.begin() + 1)" << std::endl;
    intv2.erase(intv2.begin() + 1);
    std::cout << "intv2 size = " << intv2.size() << std::endl;
    std::cout << "intv2 = ";
    for (int i = 0; i < intv2.size(); i++)
    {
        std::cout << intv2.at(i) << " ";
    }
    std::cout << std::endl;

    std::cout << "intv2.insert(intv2.begin() + 1, 2)" << std::endl;
    intv2.insert(intv2.begin() + 1, 2);
    std::cout << "intv2 size = " << intv2.size() << std::endl;
    std::cout << "intv2 = ";
    for (int i = 0; i < intv2.size(); i++)
    {
        std::cout << intv2.at(i) << " ";
    }
    std::cout << std::endl;
    std::cout << "intv2.insert(intv2.begin() + 1, 3, 42)" << std::endl;
    intv2.insert(intv2.begin() + 1, (size_t)3, 42);
    std::cout << "intv2 size = " << intv2.size() << std::endl;
    std::cout << "intv2 = ";
    for (int i = 0; i < intv2.size(); i++)
    {
        std::cout << intv2.at(i) << " ";
    }
    std::cout << std::endl;
    std::cout << "intv2.insert(intv2.begin() + 1, intv1.begin(), intv1.begin() + 3)" << std::endl;
    intv2.insert(intv2.begin() + 1, intv1.begin(), intv1.begin() + 3);
    std::cout << "intv1 = ";
    for (int i = 0; i < intv1.size(); i++)
    {
        std::cout << intv1.at(i) << " ";
    }
    std::cout << std::endl;
    std::cout << "intv2 size = " << intv2.size() << std::endl;
    std::cout << "intv2 = ";
    for (int i = 0; i < intv2.size(); i++)
    {
        std::cout << intv2.at(i) << " ";
    }
    std::cout << std::endl;

    std::cout << "intv2.max_size() = " << intv2.max_size() << std::endl;
    std::cout << "intv2.size() = " << intv2.size() << std::endl;
    std::cout << "intv2.pop_back()" << std::endl;
    intv2.pop_back();
    std::cout << "intv2.size() = " << intv2.size() << std::endl;

    std::cout << "intv1.size() = " << intv1.size() << std::endl;
    std::cout << "intv1.capacity() = " << intv1.capacity() << std::endl;
    std::cout << "intv1.shrink_to_fit()" << std::endl;
    intv1.shrink_to_fit();
    std::cout << "intv1.capacity() = " << intv1.capacity() << std::endl;
    std::cout << "intv1 = ";
    for (int i = 0; i < intv1.size(); i++)
    {
        std::cout << intv1.at(i) << " ";
    }
    std::cout << std::endl;

    std::cout << "intv1.resize(10)" << std::endl;
    intv1.resize(10);
    std::cout << "intv1.size() = " << intv1.size() << std::endl;
    std::cout << "intv1 = ";
    for (int i = 0; i < intv1.size(); i++)
    {
        std::cout << intv1.at(i) << " ";
    }
    std::cout << std::endl;

    std::cout << "intv3 = intv1" << std::endl;
    ft::vector<int> intv3 = intv1;
    std::cout << "intv3.size() = " << intv3.size() << std::endl;
    std::cout << "intv3 = ";
    for (int i = 0; i < intv3.size(); i++)
    {
        std::cout << intv3.at(i) << " ";
    }
    std::cout << std::endl;

    std::cout << "vector<bool> boolv1 <- 1 0 1 0" << std::endl;
    ft::vector<bool> boolv1;
    boolv1.push_back(true);
    boolv1.push_back(false);
    boolv1.push_back(true);
    boolv1.push_back(false);
    std::cout << "boolv1 = ";
    for (int i = 0; i < boolv1.size(); i++)
    {
        std::cout << static_cast<int>(boolv1.at(i)) << " ";
    }
    std::cout << std::endl;
    std::cout << "boolv1.flip() // only for vector<bool> function" << std::endl;
    boolv1.flip();
    std::cout << "boolv1 = ";
    for (int i = 0; i < boolv1.size(); i++)
    {
        std::cout << static_cast<int>(boolv1.at(i)) << " ";
    }
    std::cout << std::endl;
}

void test_map()
{
    ft::map<int, std::string> m1;
    m1.insert(ft::pair<int, std::string>(42, "forty-two"));
    m1.insert(ft::pair<int, std::string>(1, "one"));
    m1.insert(ft::pair<int, std::string>(22, "twenty-two"));
    m1[11] = std::string("eleven");

    for (ft::map<int, std::string>::iterator iter = m1.begin(); iter != m1.end(); iter++)
    {
        std::cout << "[" << iter->first << ", " << (*iter).second << "]" << std::endl;
    }
    std::cout << "reverse_iterator test" << std::endl;
    for (ft::map<int, std::string>::reverse_iterator iter = m1.rbegin(); iter != m1.rend(); iter++)
    {
        std::cout << "[" << iter->first << ", " << (*iter).second << "]" << std::endl;
    }
    std::cout << "m1 size = " << m1.size() << std::endl;
    std::cout << "m1 max_size = " << m1.max_size() << std::endl;

    ft::map<std::string, int> m2;
    m2["ecole"] = 42;
    m2["seoul"] = 42;
    for (ft::map<std::string, int>::iterator iter = m2.begin(); iter != m2.end(); iter++)
    {
        std::cout << "[" << iter->first << ", " << (*iter).second << "]" << std::endl;
    }

    ft::map<int, std::string> m3;
    m3[0] = "zero";
    m1.swap(m3);
    std::cout << "m1.swap(m3)" << std::endl;
    std::cout << "m1 = " << std::endl;
    for (ft::map<int, std::string>::iterator iter = m1.begin(); iter != m1.end(); iter++)
    {
        std::cout << "[" << iter->first << ", " << (*iter).second << "]" << std::endl;
    }
    std::cout << "m3 = " << std::endl;
    for (ft::map<int, std::string>::iterator iter = m3.begin(); iter != m3.end(); iter++)
    {
        std::cout << "[" << iter->first << ", " << (*iter).second << "]" << std::endl;
    }

    std::cout << "m1 size = " << m1.size() << std::endl;
    std::cout << "m1.clear()" << std::endl;
    m1.clear();
    std::cout << "m1 size = " << m1.size() << std::endl;

    std::cout << "Is m1 empty? = ";
    if (m1.empty())
        std::cout << "yes" << std::endl;
    else
        std::cout << "no" << std::endl;
    std::cout << "Is m3 empty? = ";
    if (m3.empty())
        std::cout << "yes" << std::endl;
    else
        std::cout << "no" << std::endl;
    
    std::cout << "m3 = " << std::endl;
    for (ft::map<int, std::string>::iterator iter = m3.begin(); iter != m3.end(); iter++)
    {
        std::cout << "[" << iter->first << ", " << (*iter).second << "]" << std::endl;
    }
    std::cout << "m3.erase(22)" << std::endl;
    m3.erase(22);
    std::cout << "m3 = " << std::endl;
    for (ft::map<int, std::string>::iterator iter = m3.begin(); iter != m3.end(); iter++)
    {
        std::cout << "[" << iter->first << ", " << (*iter).second << "]" << std::endl;
    }

    std::cout << "m3.find(42)" << std::endl;
    if (m3.find(42) != m3.end())
        std::cout << "OK" << std::endl;
    else
        std::cout << "KO" << std::endl;
    std::cout << "m3.find(1111)" << std::endl;
    if (m3.find(1111) != m3.end())
        std::cout << "OK" << std::endl;
    else
        std::cout << "KO" << std::endl;
    
    std::cout << "same key test" << std::endl;
    std::cout << "m3.insert(ft::pair<int, std::string>(42, \"!!!!!\"))" << std::endl;
    m3.insert(ft::pair<int, std::string>(42, "!!!!!"));
    std::cout << "m3 = " << std::endl;
    for (ft::map<int, std::string>::iterator iter = m3.begin(); iter != m3.end(); iter++)
    {
        std::cout << "[" << iter->first << ", " << (*iter).second << "]" << std::endl;
    }

    ft::map<int, std::string> m4;
    m4[1] = "first";
    m4[2] = "second";
    m4[3] = "third";
    m4[4] = "fourth";
    std::cout << "create new map(m3) for tree check" << std::endl;
    std::cout << "m4 = " << std::endl;
    for (ft::map<int, std::string>::iterator iter = m4.begin(); iter != m4.end(); iter++)
    {
        std::cout << "[" << iter->first << ", " << (*iter).second << "]" << std::endl;
    }
    std::cout << "m4.equal_range(2) -> " << std::endl;
    std::cout << m4.equal_range(2).first->first << ", " << m4.equal_range(2).first->second << std::endl;
    std::cout << m4.equal_range(2).second->first << ", " << m4.equal_range(2).second->second << std::endl;
    std::cout << "m4.equal_range(3) -> " << std::endl;
    std::cout << m4.equal_range(3).first->first << ", " << m4.equal_range(3).first->second << std::endl;
    std::cout << m4.equal_range(3).second->first << ", " << m4.equal_range(3).second->second << std::endl;

    std::cout << "m4 key_compare test" << std::endl;
    ft::map<int, std::string>::key_compare m4_keycomp = m4.key_comp();
    if (m4_keycomp(2, 4))
        std::cout << "same" << std::endl;
    else
        std::cout << "not same" << std::endl;
    if (m4_keycomp(4, 2))
        std::cout << "same" << std::endl;
    else
        std::cout << "not same" << std::endl;
    
    std::cout << "m4 value_compare test" << std::endl;
    ft::map<int, std::string>::value_compare m4_valuecomp = m4.value_comp();
    ft::pair<int, std::string> temp1;
    temp1.first = 2;
    temp1.second = "second";
    ft::pair<int, std::string> temp2;
    temp2.first = 3;
    temp2.second = "third";
    if (m4_valuecomp(temp1, temp2))
        std::cout << "same" << std::endl;
    else
        std::cout << "not same" << std::endl;
    if (m4_valuecomp(temp2, temp1))
        std::cout << "same" << std::endl;
    else
        std::cout << "not same" << std::endl;
}

void test_stack()
{
    ft::stack<int> s1;

    std::cout << "s1.size() = " << s1.size() << std::endl;
    std::cout << "s1.empty() = " << static_cast<int>(s1.empty()) << std::endl;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    std::cout << "push 3 elements" << std::endl;
    std::cout << "s1.size() = " << s1.size() << std::endl;
    std::cout << "s1.empty() = " << static_cast<int>(s1.empty()) << std::endl;

    std::cout << "s1.top() = " << s1.top() << std::endl;
    std::cout << "s1.pop()" << std::endl;
    s1.pop();
    std::cout << "s1.top() = " << s1.top() << std::endl;
    std::cout << "s1.size() = " << s1.size() << std::endl;

    std::cout << "s1.top() = 10" << std::endl;
    s1.top() = 10;
    std::cout << "s1.top() = " << s1.top() << std::endl;

    std::cout << "all pop" << std::endl;
    s1.pop();
    s1.pop();
    std::cout << "s1.size() = " << s1.size() << std::endl;
    std::cout << "s1.empty() = " << static_cast<int>(s1.empty()) << std::endl;

    s1.push(1);
    s1.push(2);
    s1.push(3);
    ft::stack<int> s2;
    s2.push(1);
    s2.push(2);
    std::cout << "s1 = 1 2 3(top), s2 = 1 2(top)" << std::endl;
    std::cout << "s1 == s1" << std::endl;
    if (s1 == s1)
        std::cout << "TRUE" << std::endl;
    else
        std::cout << "FALSE" << std::endl;
    std::cout << "s1 == s2" << std::endl;
    if (s1 == s2)
        std::cout << "TRUE" << std::endl;
    else
        std::cout << "FALSE" << std::endl;
    std::cout << "s1 > s2" << std::endl;
    if (s1 > s2)
        std::cout << "TRUE" << std::endl;
    else
        std::cout << "FALSE" << std::endl;
}

int main()
{
    // vector
    std::cout << "---< VECTOR TEST >---" << std::endl;
    timeTool::setStartTime();
    test_vector();
    timeTool::setEndTime();
    std::cout << " > Delta time = " << timeTool::getDeltaTime() << "ms" << std::endl;

    std::cout << "---------------------" << std::endl << std::endl;

    // map
    std::cout << "-----< MAP TEST >----" << std::endl;
    timeTool::setStartTime();
    test_map();
    timeTool::setEndTime();
    std::cout << " > Delta time = " << timeTool::getDeltaTime() << "ms" << std::endl;

    std::cout << "---------------------" << std::endl << std::endl;

    // stack
    std::cout << "----< STACK TEST >---" << std::endl;
    timeTool::setStartTime();
    test_stack();
    timeTool::setEndTime();
    std::cout << " > Delta time = " << timeTool::getDeltaTime() << "ms" << std::endl;

    std::cout << "---------------------" << std::endl << std::endl;

    return 0;
}