class Logger {
private:
    unordered_map<string,int> msgTimeStamps;

public:

    Logger() {

    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        if(msgTimeStamps.find(message)==msgTimeStamps.end()) { 
            msgTimeStamps[message] = timestamp;
            return true;
        }
        if (timestamp-msgTimeStamps[message]>=10) {
            msgTimeStamps[message] = timestamp;
            return true;
        }

        return false;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */