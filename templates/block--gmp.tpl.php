<?php $items = $variables['items']; ?>
<!-- <?php print render($items['gmp_zoom']); ?><br>
Key: <?php print render($items['gmp_api_key']); ?><br>
Loc: <?php print render($items['gmp_location']); ?><br>
wdt: <?php print render($items['gmp_width']); ?><br>
hgt: <?php print render($items['gmp_height']); ?><br>
-->

<iframe
  width="<?php print render($items['gmp_width']); ?>"
  height="<?php print render($items['gmp_height']); ?>"
  frameborder="<?php print render($items['gmp_frameborder']); ?>"
  style="border:0"
  src="https://www.google.com/maps/embed/v1/place?key=<?php print render($items['gmp_api_key']); ?>&zoom=<?php print render($items['gmp_zoom']); ?>&q=<?php print render($items['gmp_location']); ?>" allowfullscreen>
</iframe>
