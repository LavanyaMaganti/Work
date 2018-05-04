while(<>){
  strip;
  @a = split;
  @b = sort { $a <=> $b} @a;
  printf "%d %d\n", $b[0], $b[1];
  printf "%d %d\n", $b[0], $b[2];
  printf "%d %d\n", $b[1], $b[2];
}
