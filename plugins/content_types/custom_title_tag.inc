<?php

$plugin = array(
    'title' => t('Custom Title Tag'),
    'render callback' => 'panels_custom_title_tag_render',
    'edit form' => 'panels_custom_title_tag_edit_form',
    'description' => t('Sets the title tag of this page'),
    'category' => t('HTML Head'),
    'no title override' => TRUE,
    'single' => TRUE,
);

/**
 * @todo Please document this function.
 * @see http://drupal.org/node/1354
 */
function panels_custom_title_tag_render($subtype, $conf, $args, $contexts) {
  $content = new stdClass();
  global $panels_custom_title_pattern;

  if (isset($conf['custom_page_title_pattern'])) {
    // Set the title tag pattern here:
    $panels_custom_title_pattern = $conf['custom_page_title_pattern'];
  }

  // Pass empty data back to our page
  $content->content = '<span></span>';
  return $content;
}

function panels_custom_title_tag_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['custom_page_title_pattern'] = array(
      '#type' => 'textfield',
      '#title' => t('Custom Page Title Pattern'),
      '#default_value' => $conf['custom_page_title_pattern'],
  );

  return $form;
}

function panels_custom_title_tag_edit_form_submit(&$form, &$form_state) {
  foreach (element_children($form) as $key) {
    $form_state['conf'][$key] = $form_state['values'][$key];
  }
}