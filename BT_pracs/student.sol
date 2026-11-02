//SPDX-License-Identifier:MIT
pragma solidity^0.8.38;

contract student{
    struct Student{
        uint rollNo;
        string name;
    }

    Student[]public students;

    function addStu(uint r,string memory n)public{
        students.push(Student(r,n));
    }

    function getStu(uint i)public view returns(uint,string memory){
        return (students[i].rollNo,students[i].name);
    }

    function totalStu()public view returns(uint){
        return students.length;
    }
}