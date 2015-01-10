class textEditor
{
 public:
  bool init(char *filename);

  ULONG getline(ULONG lineno, char *buf, size_t len);
  ULONG linecount();
  
 private:
  bool init_linebuffer();
  char *buffer;
  int length;  
};
  
