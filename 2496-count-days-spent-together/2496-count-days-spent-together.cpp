class Solution {
public:
    // Turn both dates into days of the year (1-365), and the answer is just day(last) - day(first) + 1. If last < first, they never meet, and the answer is 0.
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int>months={0,31,28,31,30,31,30,31,31,30,31,30,31};
        for(int i=1;i<=12;++i) months[i]+=months[i-1];
        
        int aliceStartMonth=((arriveAlice[0]-'0')*10 +(arriveAlice[1]-'0'));
        int aliceStartDay=((arriveAlice[3]-'0')*10 +(arriveAlice[4]-'0'));
        
        int aliceEndMonth=(leaveAlice[0]-'0')*10 +(leaveAlice[1]-'0');
        int aliceEndDay=((leaveAlice[3]-'0')*10 +(leaveAlice[4]-'0'));
        
        int bobStartMonth=(arriveBob[0]-'0')*10 +(arriveBob[1]-'0');
        int bobStartDay=((arriveBob[3]-'0')*10 +(arriveBob[4]-'0'));
        
        int bobEndMonth=(leaveBob[0]-'0')*10 +(leaveBob[1]-'0');
        int bobEndDay=((leaveBob[3]-'0')*10 +(leaveBob[4]-'0'));
        
       
        int laterDays=0;
        if(leaveAlice<=leaveBob)
        {
            laterDays=months[aliceEndMonth-1]+aliceEndDay;
        }
        else laterDays=months[bobEndMonth-1]+bobEndDay;
        
        int beginDays=0;
        if(arriveAlice>=arriveBob)
        {
            beginDays=months[aliceStartMonth-1]+aliceStartDay;
        }
        else beginDays=months[bobStartMonth-1]+bobStartDay;

        return max(0, (laterDays-beginDays)+1);
    }
};