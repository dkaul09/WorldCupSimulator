# WorldCupSimulator

**Project Description**

This C++ powered World Cup Simulator has been modelled on using mathematical models such as the Poission Distribution and football (soccer) statistics such as xG(expected goals) to predict how maay teams can score against their opponents. 

This simulator consists of the 32 teams that took part in the FIFA Men's World Cup 2022. In addition, I have also attached an excel spreadsheet that summarizes each of the 32 teams' attacking and defensvie strength, which is used to calculate the xG of a team against their opponent. I will later on explain how I calculated the strengths and adjusted them to make the simulations more accurate. 



**How to run the install project**

When you have downloaded the files, you can run this command to compile the code: g++ knockout_sim.cpp main.cpp ....


Then use ./tourny teams.txt and then program will start. 

**How the project works**

1. First the program will parse in the 32 teams, their attacking rating and defensive rating, which can also be found on the Excel spreadsheet.
2. The user will then be prompted to choose whether they want randomized groups or fixed groups from the 2022 World Cup.
   ![image](https://github.com/dkaul09/WorldCupSimulator/assets/111927365/6cc16d44-cf64-41ac-9436-ddd0212dcf42)


