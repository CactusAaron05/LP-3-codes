//SPDX-License-Identifier:MIT
pragma solidity^0.8.38;

contract bank{
    mapping(address=>uint)public balances;

    function deposit()public payable{
        balances[msg.sender]+=msg.value;
    }

    function withdraw(uint amount)public{
        require(amount>0,"amount cannot be negative");
        balances[msg.sender] -=amount;
        (bool success,)=payable(msg.sender).call{value:amount}("");
        require(success,"transaction fail");
    }

    function getBalence()public view returns(uint){
        return balances[msg.sender];
    }
}