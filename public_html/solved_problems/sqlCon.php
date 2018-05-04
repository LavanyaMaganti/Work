<html>
<body>
<p>This is to check dATA CONNECTIVITY</p>

<?php

  if ($db =@sqlite_open('quotes.db', 0666, $error))
      {
          echo 'Connected to the database.';
              sqlite_close($db);
                } else {
                    echo 'Connection failed: ' . htmlspecialchars
                          ($error);
                            }
?>
</body>
</html>
