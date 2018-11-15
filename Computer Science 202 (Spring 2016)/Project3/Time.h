class Time{
 public:
  Time();
  Time(int hrs, int mns);

  friend ostream& operator<<(ostream& os, const Time& time);
  friend Time& operator+(const Time& timeVal, const int& amount);
  friend bool operator<(const Time& time1, const Time& time2);

  int GetHours() const;
  int GetMins() const;
  void SetHours(int hours);
  void SetMins(int mins);

 private:
  int m_hours;
  int m_mins;
    
};
