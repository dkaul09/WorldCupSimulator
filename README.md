# WorldCupSimulator

**Project Description**

This C++ powered World Cup Simulator has been modelled on using mathematical models such as the Poission Distribution and football (soccer) statistics such as expected goals to predict how maay teams can score against their opponents. 

This simulator consists of the 32 teams that took part in the FIFA Men's World Cup 2022. In addition, I have also attached an excel spreadsheet that summarizes each of the 32 teams' attacking and defensvie strength, which is used to calculate the xG of a team against their opponent. I will later on explain how I calculated the strengths and adjusted them to make the simulations more accurate.

I really enjoyed building this project as I am a huge football (soccer) fan and I was always curious about how betting companies or sport studios were able to predict matches using data. 


**What is in the Excel Sheet and how has the data been calculated?** 

Inside the Excel sheet, we have a summary of each of the 32 teams performances in the World Cup since 1934 with information such as how many goals they have scored and conceded. Let us look at an example. All the information I added to this sheet was taken from: https://en.wikipedia.org/wiki/FIFA_World_Cup_records_and_statistics 

![image](https://github.com/dkaul09/WorldCupSimulator/assets/111927365/23a4d63f-dd48-455a-9fe8-b7e48669eb33)

Above are the statistics of the German National Team. The ATTK Rating determines how strong their attack is. The higher the number, the better it is. However, it works the opposite for the DEF rating. The lower the Defensive rating, the better. 

<ins>_Calculating the ATTK Rating and Defense Rating_</ins>

I calculated the ATTK Rating by dividing the goals scored by Germany by their matches played. I then further divide that value by the average value of goals scored by each of the 32 teams. I then do the same with the DEFF Rating, but instead of using goals scored, I use goals conceded. 

<ins>_Fine tuning the ratings_</ins>

To make the model as accurate and realistic as possible, I have fine tuned some of the teams' attacking and defensive ratings using the current FIFA Men's Teams Rankings. Let's look at Germany again.

Germany are currently 15th in Men's Rankings and it could be assumed that they are not good as they were in 2014 (given that in the last 2 World Cups they were not able to advance to the knockout stages). Hence, with teams outside the Top 10, I add a "penalty" to the ATTK and DEF ratings of the teams.

If the team's rankings are in the range of 11th - 20th, I add a 10% penalty, making reducing a team's ATTK rating by 5% and increasing their team's DEF Rating by 5%. 

If the team's rankings are in the range of 21st - 30th, I add a 20% penalty, making reducing a team's ATTK rating by 10% and increasing their team's DEF Rating by 10%, and so on. 

Hence, Germany's ATTK Rating went from 1.403 (x 0.95) to 1.333 and their DEF Rating went from 0.879 (x 1.05) to 0.923.


**How to run the project?**

When you have downloaded the files, you can run this command to compile the code: 
g++ main.cpp knockout_sim.cpp match_simulator.cpp team.cpp teamparser.cpp -o tourny


Then use ./tourny teams.txt and then program will start. 

**How the project works?**

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

**Some of the challenges I faced and how I overcame them**

One of the challenges I faced when working on this project was finding an appropriate method to model the data on. I did not know where to begin at all and so I spent days researching all the different methods to calculate goals, from the ELO Rating System to the Poission Distribution (which is the model I ended up using at the end). 

However, at the end, I came across this video (https://www.youtube.com/watch?v=vg5BxFCdYnE&t=840s). Inspired by the video, I added the model mentioned in the video in my project, but added an extra feature of fine-tuning the values calculated using the Men's Rankings.

**What features I would include next time if I return to this project and any possible improvements?**

If I come back to this project, I would add features such as showing the goal scorer of each goal in the match alongside the minute scored. In addition, I would also add dialogue to describe the events of a match, such as yellow cards, penalties, etc, to make it more the simulation a bit more eventful and entertaining.

In addition, to improve the accuracy of the model, I may consider all football matches that all 32 teams have played and their performances, while taking into account whether they have played at home, away, or neutral event at those matches since the venue location is very instrumental in football.
