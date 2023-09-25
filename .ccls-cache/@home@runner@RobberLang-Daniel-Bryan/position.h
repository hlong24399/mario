class position
{
public:
  int r;
  int c;

public:
  position(int r, int c) { this->r = r; this->c = c; } 
  void setPosition(int r, int c) { this->r = r; this->c = c; }
  int getRow() { return this->r; }
  int getCol() { return this-> c; }
};