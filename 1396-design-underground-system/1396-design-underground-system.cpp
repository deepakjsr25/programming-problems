class UndergroundSystem {
public:
    unordered_map<int,pair<string,int>> m_in;
    map<pair<string,string>,pair<int,int>> m_avg;
    UndergroundSystem() {}
    
    void checkIn(int id, string stationName, int t) {
        m_in[id]=make_pair(stationName,t);
        return;
    }
    
    void checkOut(int id, string stationName, int t) {
        auto it = m_in[id];
        if(m_avg.find(make_pair(it.first,stationName))==m_avg.end()){
            m_avg[make_pair(it.first,stationName)] = make_pair(t-it.second,1);
            return;
        }
        
        auto it2 = m_avg[make_pair(it.first,stationName)];
        m_avg[make_pair(it.first,stationName)] = make_pair(it2.first+t-it.second,it2.second+1);
        
        return;
    }
    
    double getAverageTime(string startStation, string endStation) {
        auto it = m_avg[make_pair(startStation,endStation)];
        
        return it.first/(double)it.second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */