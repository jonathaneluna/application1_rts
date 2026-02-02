# Basic information
Name: Jonathan Luna\
UCFID: 5458486\
Class: EEE 5862\
Assignment: Application 1
# Question 1

When I increased the delay for the print task, 
I saw that there was no delay or alteration in the timing. 
When I tried to introduce a longer print statement, 
I saw that there was no delay in terms of the timing of the LED.
When the print statement offered had a delay that was 
noticeable by a few milliseconds. 

# Question 2

 When I increased the load during the printing task, 
the print task was stuck in a loop. This prevented the LED from blinking 
and any print task or blinking action from that task was not able to be activated.

# Question 3

 When sending complex information like telemetry data from a satellite, 
it would be important to keep messages and printing tasks only long enough for 
important data to be sent to the user while maintaining short print statements to 
minimize any potential delay for other important task during operation. 
I believe that for this application while greatly simplified from an actual 
satellite application, would greatly be impacted from timing of the operations 
in a predictable manner as gaps longer than expected from standard operation would 
greatly decrease quality such as weather forecast and GPS mapping that would 
 a satellite to send information critical for those operations

# Question 4

 I measured period in my code by creating three new variables. CurrentTime, PastTime, and Period each with a further specification if there were for the data task or the telemetry. Before startup, all variables were set to 0.
For the LED task. I kept track of the time when the LED did a fully cycle of Turning on and off. I placed this time value in the CurrentTime variable. Once this full operation occurred, I made the Period variable equal to CurrentTime - Pastime to obtain the period. I then placed the old CurrentTime into the PastTime variable. This allowed me to repeat this process to obtain the LED period accurately while posting individual times.
For the telemetry task, The same principle was used. Once all data was obtained, the program placed the current time and compared to previous time where the difference would be equal to the period.
The period of the LED task was 500 ms for a full cycle of blinking and the period of the Print Task was 10000ms. This allowed for the true time between task despite an initial delay in the code of 10ms

# Question 5
Yes our system maintained the timing requirements. We know this because we set
out system to detect the time it took to fully complete a task and subtract it
from the past time. This allowed us to determine that the LED cycle takes 500ms for total completion and the print cycle to take 10000ms for total completion

# Question 6

I was able to get the LED to miss its timing requirements by implementing the period method mentioned in Question 4 with a slight alteration. In order to preserve the inverting variable in the original code. I added a counter variable to keep tracts of how many times the LED light changed. Once it got to the counter variable of 2, it triggered the if statement which captured the current time and subtracted from the past time generating the period. This led to a a period where the light did a full cycle by 2.5 seconds instead of .25 seconds
# Question 7 
Yes, by utilizing multitasking principles. We were able to achieve timing determinism as the code consistently achieved the 500 ms and 10000 ms periods desired for the task.
