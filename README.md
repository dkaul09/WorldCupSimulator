# WorldCupSimulator

**Project Description**

This C++ powered World Cup Simulator has been modelled on using mathematical models such as the Poission Distribution and football (soccer) statistics such as expected goals to predict how maay teams can score against their opponents. 

This simulator consists of the 32 teams that took part in the FIFA Men's World Cup 2022. In addition, I have also attached an excel spreadsheet that summarizes each of the 32 teams' attacking and defensvie strength, which is used to calculate the xG of a team against their opponent. I will later on explain how I calculated the strengths and adjusted them to make the simulations more accurate. 


**What is in the Excel Sheet and how has the data been calculated?** 
Inside the Excel sheet,



**How to run the install project**

When you have downloaded the files, you can run this command to compile the code: g++ knockout_sim.cpp main.cpp ....


Then use ./tourny teams.txt and then program will start. 

**How the project works**

1. First the program will parse in the 32 teams, their attacking rating and defensive rating, which can also be found on the Excel spreadsheet.
2. The user will then be prompted to choose whether they want randomized groups or fixed groups from the 2022 World Cup. I will be choosing the fixed groups in this example.


   ![image](https://github.com/dkaul09/WorldCupSimulator/assets/111927365/f0ae262a-68bb-4ae6-a4a3-8b3e5e8d7c5b)

   
3.  The user will then be prompted to hit enter for each match to run.
   ![image](https://github.com/dkaul09/WorldCupSimulator/assets/111927365/8fd1746e-1b79-4196-aa50-6baab68098e0)

 In the above example, eX represents a team's expected goals. Netherlands were favoured to win this matchup by a goal as they were expected to score 2 goals and Senegal were expected to score 1. 
 However, the match ended in a draw. 

 In order to model the goals, what I did was apply the Poission Distribution, with the team's expected goals (eX) as a mean, in order to determine how many goals a team would score against the other. 

4. Below is a points table that is shown after each matchday after teams have faced each other statistics like goals scored and points.
   ![image](https://github.com/dkaul09/WorldCupSimulator/assets/111927365/78f1b4ae-163c-4376-8d56-b7989e663977)

5. After 3 match days are done, then the knockout round will commence. From the 32, 16 will advance to the knockout stages. From there, 8 will advance and soon till 1 team remains from each bracket, setting up the final.



![image](https://github.com/dkaul09/WorldCupSimulator/assets/111927365/eb11bc21-c510-4f53-a524-35b9537ff066)

   
6. In the event, that the goals scored by both teams in the knockout stages are the same, the game will go to penalties, and there will 50/50 chance of both teams to go through in this cases. Hence, it is randomly decided who advances on penalties.


7. The Final

   ![image](https://github.com/dkaul09/WorldCupSimulator/assets/111927365/408852c3-45ad-41a6-bf07-ad9267bd92bb)



   In our simulation, Argentina wins the World Cup (just like 2022!).








**Some of the challenges I faced**

One of the challenges I faced was trying to find an approriate model 



**What features I would include next time if I return to this project **
