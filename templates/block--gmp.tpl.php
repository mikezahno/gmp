<?php $items = $variables['items']; ?>

<iframe
  width="<?php print render($items['gmp_width']); ?>"
  height="<?php print render($items['gmp_height']); ?>"
  frameborder=0
  style="border:0"
  src="https://www.google.com/maps/embed/v1/place?key=<?php print render($items['gmp_api_key']); ?>&zoom=<?php print render($items['gmp_zoom']); ?>&q=<?php print render($items['gmp_location']); ?>" allowfullscreen>
</iframe>
